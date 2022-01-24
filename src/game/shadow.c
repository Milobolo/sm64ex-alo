#include <PR/ultratypes.h>
#include <PR/gbi.h>

#include "engine/math_util.h"
#include "engine/surface_collision.h"
#include "behavior_data.h"
#include "geo_misc.h"
#include "level_table.h"
#include "memory.h"
#include "level_update.h"
#include "object_list_processor.h"
#include "rendering_graph_node.h"
#include "segment2.h"
#include "shadow.h"
#include "sm64.h"

/**
 * @file shadow.c
 * This file implements a self-contained subsystem used to draw shadows.
 */

/**
 * An array consisting of all the hardcoded rectangle shadows in the game.
 */
static ShadowRectangle sShadowRectangles[2] = {
    { 7.2f, 4.6f, TRUE }, // Spindel
    { 4.0f, 3.6f, TRUE }, // Whomp
};


struct Shadow gCurrShadow;
struct Shadow *s = &gCurrShadow;


/**
 * Shrink a shadow when its parent object is further from the floor, given the
 * initial size of the shadow and the current distance.
 */
f32 scale_shadow_with_distance(f32 initial, f32 distFromFloor) {

    if (distFromFloor <= 0.0f) {
        return initial;
    } else if (distFromFloor >= 600.0f) {
        return initial * 0.5f;
>>>>>>> master
    } else {
        return initial * (1.0f - ((distFromFloor * 0.5f) / 600.0f));
    }
}

/**
 * Dim a shadow when its parent object is further from the ground.
 */
s32 dim_shadow_with_distance(u8 solidity, f32 distFromFloor) {
    if (solidity < 121) {
        return solidity;
    } else if (distFromFloor <= 0.0f) {
        return solidity;
    } else if (distFromFloor >= 600.0f) {
        return 120;
    } else {
<<<<<<< HEAD
        ret = ((120 - solidity) * distFromFloor) / 600.0f + (f32) solidity;
        return ret;
    }
}

/**
 * Return the water level below a shadow, or 0 if the water level is below
 * -10,000.
 */
f32 get_water_level_below_shadow(struct Shadow *s) {
    f32 waterLevel = find_water_level(s->parentX, s->parentZ);
    if (waterLevel < FLOOR_LOWER_LIMIT_SHADOW) {
        return 0;
    } else if (s->parentY >= waterLevel && s->floorHeight <= waterLevel) {
        gShadowAboveWaterOrLava = TRUE;
        return waterLevel;
=======
        return (((120 - solidity) * distFromFloor) / 600.0f) + (f32) solidity;
>>>>>>> master
    }
}

/**
 * Initialize a shadow. Return 0 on success, 1 on failure.
 *
 * @param pos Position of the parent object (not the shadow)
 * @param shadowScale Diameter of the shadow
 * @param overwriteSolidity Flag for whether the existing shadow solidity should
 *                          be dimmed based on its distance to the floor
 */
s32 init_shadow(f32 distToShadow, s16 shadowScale, s8 shadowType, u8 overwriteSolidity) {
    f32 baseScale;

    if (shadowType != SHADOW_SQUARE_PERMANENT) {
        // Set solidity and scale based on distance.

<<<<<<< HEAD
    s->floorHeight = find_floor_height_and_data(s->parentX, s->parentY, s->parentZ, &floorGeometry);

    if (gEnvironmentRegions != 0) {
        waterLevel = get_water_level_below_shadow(s);
    }
    if (gShadowAboveWaterOrLava) {
        //! @bug Use of potentially undefined variable `waterLevel`
        s->floorHeight = waterLevel;

        // Assume that the water is flat.
        s->floorNormalX = 0;
        s->floorNormalY = 1.0f;
        s->floorNormalZ = 0;
        s->floorOriginOffset = -waterLevel;
    } else {
        // Don't draw a shadow if the floor is lower than expected possible,
        // or if the y-normal is negative (an unexpected result).
        if (s->floorHeight < FLOOR_LOWER_LIMIT_SHADOW || floorGeometry->normalY <= 0.0) {
            return 1;
        }

        s->floorNormalX = floorGeometry->normalX;
        s->floorNormalY = floorGeometry->normalY;
        s->floorNormalZ = floorGeometry->normalZ;
        s->floorOriginOffset = floorGeometry->originOffset;
    }

    if (overwriteSolidity) {
        s->solidity = dim_shadow_with_distance(overwriteSolidity, yPos - s->floorHeight);
    }

    s->shadowScale = scale_shadow_with_distance(shadowScale, yPos - s->floorHeight);

    s->floorDownwardAngle = atan2_deg(s->floorNormalZ, s->floorNormalX);

    floorSteepness = sqrtf(s->floorNormalX * s->floorNormalX + s->floorNormalZ * s->floorNormalZ);

    // This if-statement avoids dividing by 0.
    if (floorSteepness == 0.0f) {
        s->floorTilt = 0;
    } else {
        s->floorTilt = 90.0f - atan2_deg(floorSteepness, s->floorNormalY);
    }
    return 0;
}

/**
 * Given a `vertexNum` from a shadow with nine vertices, update the
 * texture coordinates corresponding to that vertex. That is:
 *      0 = (-15, -15)         1 = (0, -15)         2 = (15, -15)
 *      3 = (-15,   0)         4 = (0,   0)         5 = (15,   0)
 *      6 = (-15,  15)         7 = (0,  15)         8 = (15,  15)
 */
void get_texture_coords_9_vertices(s8 vertexNum, s16 *textureX, s16 *textureY) {
    *textureX = vertexNum % 3 * 15 - 15;
    *textureY = vertexNum / 3 * 15 - 15;
}

/**
 * Given a `vertexNum` from a shadow with four vertices, update the
 * texture coordinates corresponding to that vertex. That is:
 *      0 = (-15, -15)         1 = (15, -15)
 *      2 = (-15,  15)         3 = (15,  15)
 */
void get_texture_coords_4_vertices(s8 vertexNum, s16 *textureX, s16 *textureY) {
    *textureX = (vertexNum % 2) * 2 * 15 - 15;
    *textureY = (vertexNum / 2) * 2 * 15 - 15;
}

/**
 * Make a shadow's vertex at a position relative to its parent.
 *
 * @param vertices A preallocated display list for vertices
 * @param index Index into `vertices` to insert the vertex
 * @param relX,relY,relZ Vertex position relative to its parent object
 * @param alpha Opacity of the vertex
 * @param shadowVertexType One of SHADOW_WITH_9_VERTS or SHADOW_WITH_4_VERTS
 */
void make_shadow_vertex_at_xyz(Vtx *vertices, s8 index, f32 relX, f32 relY, f32 relZ, u8 alpha,
                               s8 shadowVertexType) {
    s16 vtxX = round_float(relX);
    s16 vtxY = round_float(relY);
    s16 vtxZ = round_float(relZ);
    s16 textureX, textureY;

    switch (shadowVertexType) {
        case SHADOW_WITH_9_VERTS:
            get_texture_coords_9_vertices(index, &textureX, &textureY);
            break;
        case SHADOW_WITH_4_VERTS:
            get_texture_coords_4_vertices(index, &textureX, &textureY);
            break;
    }

    // Move the shadow up and over slightly while standing on a flying carpet.
    if (sMarioOnFlyingCarpet) {
        vtxX += 5;
        vtxY += 5;
        vtxZ += 5;
    }
    make_vertex(vertices, index, vtxX, vtxY, vtxZ, textureX << 5, textureY << 5, 255, 255, 255,
                alpha // shadows are black
    );
}

/**
 * Given an (x, z)-position close to a shadow, extrapolate the y-position
 * according to the floor's normal vector.
 */
f32 extrapolate_vertex_y_position(struct Shadow s, f32 vtxX, f32 vtxZ) {
    return -(s.floorNormalX * vtxX + s.floorNormalZ * vtxZ + s.floorOriginOffset) / s.floorNormalY;
}

/**
 * Given a shadow vertex with the given `index`, return the corresponding texture
 * coordinates ranging in the square with corners at (-1, -1), (1, -1), (-1, 1),
 * and (1, 1) in the x-z plane. See `get_texture_coords_9_vertices()` and
 * `get_texture_coords_4_vertices()`, which have similar functionality, but
 * return 15 times these values.
 */
void get_vertex_coords(s8 index, s8 shadowVertexType, s8 *xCoord, s8 *zCoord) {
    *xCoord = index % (3 - shadowVertexType) - 1;
    *zCoord = index / (3 - shadowVertexType) - 1;

    // This just corrects the 4-vertex case to have consistent results with the
    // 9-vertex case.
    if (shadowVertexType == SHADOW_WITH_4_VERTS) {
        if (*xCoord == 0) {
            *xCoord = 1;
        }
        if (*zCoord == 0) {
            *zCoord = 1;
        }
    }
}

/**
 * Populate `xPosVtx`, `yPosVtx`, and `zPosVtx` with the (x, y, z) position of the
 * shadow vertex with the given index. If the shadow is to have 9 vertices,
 * then each of those vertices is clamped down to the floor below it. Otherwise,
 * in the 4 vertex case, the vertex positions are extrapolated from the center
 * of the shadow.
 *
 * In practice, due to the if-statement in `make_shadow_vertex()`, the 9
 * vertex and 4 vertex cases are identical, and the above-described clamping
 * behavior is overwritten.
 */
void calculate_vertex_xyz(s8 index, struct Shadow s, f32 *xPosVtx, f32 *yPosVtx, f32 *zPosVtx,
                          s8 shadowVertexType) {
    f32 tiltedScale = cosf(s.floorTilt * M_PI / 180.0f) * s.shadowScale;
    f32 downwardAngle = s.floorDownwardAngle * M_PI / 180.0f;
    f32 halfScale;
    f32 halfTiltedScale;
    s8 xCoordUnit;
    s8 zCoordUnit;
    struct FloorGeometry *dummy;

    // This makes xCoordUnit and yCoordUnit each one of -1, 0, or 1.
    get_vertex_coords(index, shadowVertexType, &xCoordUnit, &zCoordUnit);

    halfScale = (xCoordUnit * s.shadowScale) / 2.0f;
    halfTiltedScale = (zCoordUnit * tiltedScale) / 2.0f;

    *xPosVtx = (halfTiltedScale * sinf(downwardAngle)) + (halfScale * cosf(downwardAngle)) + s.parentX;
    *zPosVtx = (halfTiltedScale * cosf(downwardAngle)) - (halfScale * sinf(downwardAngle)) + s.parentZ;

    if (gShadowAboveWaterOrLava) {
        *yPosVtx = s.floorHeight;
=======
        if (overwriteSolidity) {
            s->solidity = dim_shadow_with_distance(overwriteSolidity, distToShadow);
        }

        baseScale = scale_shadow_with_distance(shadowScale, distToShadow);
>>>>>>> master
    } else {
        s->solidity = overwriteSolidity;
        baseScale = shadowScale;
    }
    vec3f_set(s->scale, baseScale, baseScale, baseScale);

    return !(s->solidity);
}

/**
 * Linearly interpolate a shadow's solidity between zero and finalSolidity
 * depending on curr's relation to start and end.
 */
void linearly_interpolate_solidity_positive(u8 finalSolidity, s16 curr, s16 start,
                                            s16 end) {
    if (curr >= 0 && curr < start) {
        s->solidity = 0;
    } else if (end < curr) {
        s->solidity = finalSolidity;
    } else {
        s->solidity = (f32) finalSolidity * (curr - start) / (end - start);
    }
}

/**
 * Linearly interpolate a shadow's solidity between initialSolidity and zero
 * depending on curr's relation to start and end. Note that if curr < start,
 * the solidity will be zero.
 */
void linearly_interpolate_solidity_negative(u8 initialSolidity, s16 curr, s16 start,
                                            s16 end) {
    // The curr < start case is not handled. Thus, if start != 0, this function
    // will have the surprising behavior of hiding the shadow until start.
    // This is not necessarily a bug, since this function is only used once,
    // with start == 0.
    if (curr >= start && end >= curr) {
        s->solidity = ((f32) initialSolidity * (1.0f - (f32)(curr - start) / (end - start)));
    } else {
        s->solidity = 0;
    }
}

/**
 * Change a shadow's solidity based on the player's current animation frame.
 */
s32 correct_shadow_solidity_for_animations(u8 initialSolidity) {
    s16 animFrame = gMarioObject->header.gfx.animInfo.animFrame;
    switch (gMarioObject->header.gfx.animInfo.animID) {
        case MARIO_ANIM_IDLE_ON_LEDGE:
            return SHADOW_SOLIDITY_NO_SHADOW;
        case MARIO_ANIM_FAST_LEDGE_GRAB:
            linearly_interpolate_solidity_positive(initialSolidity, animFrame,  5, 14);
            return SHADOW_SOILDITY_ALREADY_SET;
        case MARIO_ANIM_SLOW_LEDGE_GRAB:
            linearly_interpolate_solidity_positive(initialSolidity, animFrame, 21, 33);
            return SHADOW_SOILDITY_ALREADY_SET;
        case MARIO_ANIM_CLIMB_DOWN_LEDGE:
            linearly_interpolate_solidity_negative(initialSolidity, animFrame,  0,  5);
            return SHADOW_SOILDITY_ALREADY_SET;
        default:
            return SHADOW_SOLIDITY_NOT_YET_SET;
    }
}

#ifdef ENABLE_VANILLA_LEVEL_SPECIFIC_CHECKS
/**
 * Slightly change the height of a shadow in levels with lava.
 */
<<<<<<< HEAD
void correct_lava_shadow_height(struct Shadow *s) {
    if (gCurrLevelNum == LEVEL_BITFS && sSurfaceTypeBelowShadow == SURFACE_BURNING) {
        if (s->floorHeight < -3000.0f) {
            s->floorHeight = -3062.0f;
            gShadowAboveWaterOrLava = TRUE;
        } else if (s->floorHeight > 3400.0f) {
            s->floorHeight = 3492.0f;
            gShadowAboveWaterOrLava = TRUE;
        }
    } else if (gCurrLevelNum == LEVEL_LLL && gCurrAreaIndex == 1
               && sSurfaceTypeBelowShadow == SURFACE_BURNING) {
        s->floorHeight = 5.0f;
        gShadowAboveWaterOrLava = TRUE;
=======
void correct_lava_shadow_height(f32 *floorHeight) {
    if (gCurrLevelNum == LEVEL_BITFS) {
        if (*floorHeight < -3000.0f) {
            *floorHeight = -3062.0f;
            s->isDecal = FALSE;
        } else if (*floorHeight > 3400.0f) {
            *floorHeight = 3492.0f;
            s->isDecal = FALSE;
        }
    } else if (gCurrLevelNum == LEVEL_LLL
               && gCurrAreaIndex == 1) {
        *floorHeight = 5.0f;
        s->isDecal = FALSE;
>>>>>>> master
    }
}
#endif

/**
 * Add a shadow to the given display list.
 * shadowType 0 uses a circle texture, the rest use a square texture.
 * Uses environment alpha for shadow solidity.
 */
static void add_shadow_to_display_list(Gfx *displayListHead, s8 shadowType) {
    if (shadowType == SHADOW_CIRCLE) {
        gSPDisplayList(displayListHead++, dl_shadow_circle);
    } else {
        gSPDisplayList(displayListHead++, dl_shadow_square);
    }
    gDPSetEnvColor(displayListHead++, 255, 255, 255, s->solidity);
    gSPDisplayList(displayListHead++, dl_shadow_end);
    gSPEndDisplayList(displayListHead);
}

//! TODO:
//      - Breakout create_shadow_below_xyz into multiple functions
/**
 * Create a shadow at the absolute position given, with the given parameters.
 * Return a pointer to the display list representing the shadow.
 */
Gfx *create_shadow_below_xyz(Vec3f pos, s16 shadowScale, u8 shadowSolidity, s8 shadowType, s8 shifted) {
    struct Object *obj = gCurGraphNodeObject;
    // Check if the object exists.
    if (obj == NULL) {
        return NULL;
    }

    // The floor underneath the object.
    struct Surface *floor = NULL;
    // The y-position of the floor (or water or lava) underneath the object.
    f32 floorHeight = FLOOR_LOWER_LIMIT_MISC;
    f32 x = pos[0];
    f32 y = pos[1];
    f32 z = pos[2];
    s8 isPlayer   = (obj == gMarioObject);
    s8 notHeldObj = (gCurGraphNodeHeldObject == NULL);

    // Attempt to use existing floors before finding a new one.
    if (notHeldObj && isPlayer && gMarioState->floor) {
        // The object is Mario and has a referenced floor.
        floor       = gMarioState->floor;
        floorHeight = gMarioState->floorHeight;
    } else if (notHeldObj && obj->oFloor) {
        // The object is not Mario but has a referenced floor.
        //! Some objects only get their oFloor from bhv_init_room, which skips dynamic floors.
        floor       = obj->oFloor;
        floorHeight = obj->oFloorHeight;
    } else {
        // The object has no referenced floor, so find a new one.
        // gCollisionFlags |= COLLISION_FLAG_RETURN_FIRST;
        floorHeight = find_floor(x, y, z, &floor);

        // No shadow if the position is OOB.
        if (floor == NULL) {
            return NULL;
        }

        // Skip shifting the shadow height later, since the find_floor call above uses the already shifted position.
        shifted = FALSE;
    }

    // The shadow is a decal by default.
    s->isDecal = TRUE;

    // Check for water under the shadow.
    f32 waterLevel = find_water_level(x, z);

    // Whether the floor is an environment box rather than an actual surface.
    s32 isEnvBox = FALSE;

    if (waterLevel > FLOOR_LOWER_LIMIT_MISC
        && y >= waterLevel
        && floorHeight <= waterLevel) {
        // Skip shifting the shadow height later, since the find_water_level_and_floor call above uses the already shifted position.
        shifted = FALSE;

        // If there is water under the shadow, put the shadow on the water.
        floorHeight = waterLevel;

        // Don't use the decal layer, since water is transparent.
        s->isDecal = FALSE;

        // Check whether the water is an environment box or a water surface.
        isEnvBox = TRUE;
    } else { // Normal surfaces:
        s16 type = floor->type;
        if (type == SURFACE_ICE) {
            // Ice floors are usually transparent.
            s->isDecal = FALSE;
#ifdef ENABLE_VANILLA_LEVEL_SPECIFIC_CHECKS
        } else if (type == SURFACE_BURNING) {
            // Set the shadow height to the lava height in specific areas.
            correct_lava_shadow_height(&floorHeight);
#endif
        } else if (floor->object != NULL
                   && floor->object->behavior == segmented_to_virtual(bhvPlatformOnTrack)
                   && floor->object->oPlatformOnTrackType == PLATFORM_ON_TRACK_TYPE_CARPET) {
            // Raise the shadow 5 units so the shadow doesn't clip into the flying carpet.
            floorHeight += 5;
            // The flying carpet is transparent.
            s->isDecal = FALSE;
        }
    }

    f32 nx, ny, nz;
    if (isEnvBox) {
        // Assume the floor is flat.
        nx = 0.0f;
        ny = 1.0f;
        nz = 0.0f;
    } else {
        // Read the floor's normals.
        nx = floor->normal.x;
        ny = floor->normal.y;
        nz = floor->normal.z;

        // No shadow if the y-normal is negative (an unexpected result).
        if (ny <= 0.0f) {
            return NULL;
        }

        // If the animation changes the shadow position, move its height to the new position.
        if (shifted) {
            floorHeight = -((x * nx) + (z * nz) + floor->originOffset) / ny;
        }
    }

    // No shadow if the floor is lower than expected possible,
    if (floorHeight < FLOOR_LOWER_LIMIT_MISC) {
        return NULL;
    }

    // Get the vertical distance to the shadow, now that the final shadow height is set.
    f32 distToShadow = (y - floorHeight);

    // No shadow if the object is below it.
    if (distToShadow < -80.0f) {
        return NULL;
    }

    // No shadow if the non-Mario object is too high.
    if (!isPlayer && distToShadow > 1024.0f) {
        return NULL;
    }

    vec3f_set(s->floorNormal, nx, ny, nz);

    if (isPlayer) {
        // Set the shadow solidity manually for certain Mario animations.
        s32 solidityAction = correct_shadow_solidity_for_animations(shadowSolidity);
        switch (solidityAction) {
            case SHADOW_SOLIDITY_NO_SHADOW:
                return NULL;
            case SHADOW_SOILDITY_ALREADY_SET:
                if (init_shadow(distToShadow, shadowScale, shadowType, /* overwriteSolidity */ 0)) {
                    return NULL;
                }
                break;
            case SHADOW_SOLIDITY_NOT_YET_SET:
                if (init_shadow(distToShadow, shadowScale, shadowType, shadowSolidity)) {
                    return NULL;
                }
                break;
            default:
                return NULL;
        }
    } else {
        if (init_shadow(distToShadow, shadowScale, shadowType, shadowSolidity)) {
            return NULL;
        }

        // Get the scaling modifiers for rectangular shadows (Whomp and Spindel).
        if (shadowType >= SHADOW_RECTANGLE_HARDCODED_OFFSET) {
            s8 idx = shadowType - SHADOW_RECTANGLE_HARDCODED_OFFSET;
            s->scale[0] *= sShadowRectangles[idx].scaleX;
            s->scale[2] *= sShadowRectangles[idx].scaleZ;
            if (sShadowRectangles[idx].scaleWithDistance) {
                scale_shadow_with_distance(s->scale[0], distToShadow);
                scale_shadow_with_distance(s->scale[2], distToShadow);
            }
        }
    }

    Gfx *displayList = alloc_display_list(4 * sizeof(Gfx));

    if (displayList == NULL) {
        return NULL;
    }

    // Generate the shadow display list with type and solidity.
    add_shadow_to_display_list(displayList, shadowType);

    // Move the shadow position to the floor height.
    pos[1] = floorHeight;

    return displayList;
}