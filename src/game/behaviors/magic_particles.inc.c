extern struct Surface gHoverPseudoFloor;

void hover_particle_loop(void){
	obj_copy_pos_and_angle(o, o->parentObj);
	if (gHoverPseudoFloor.room == 90 || gMarioState->floor != &gHoverPseudoFloor){
		o->parentObj->oActiveParticleFlags &= (ACTIVE_PARTICLE_HOVER ^ 0xFFFFFFFF);
		obj_mark_for_deletion(o);
	}else{
		o->oOpacity = 255-(u32)((f32)gHoverPseudoFloor.room) * 255.0f/ 90.0f;
	}
}