#ifndef _H3_COMPONENTS_PLAYERCOMPONENT_H_
#define _H3_COMPONENTS_PLAYERCOMPONENT_H_

#include <h3.h>

#define PlayerCOMPONENT_TYPEID 0x80000001

H3_CAPI_BEGIN_BLOCK
void PlayerComponent_Terminate(void* properties);
void PlayerComponent_Update(H3Handle h3, SH3Transform* transform, void* properties);

void* PlayerComponent_CreateProperties(const char* texturePath, uint8_t anchor);
void Player_Component_Collisions(H3Handle Object, SH3Collision collisions);
H3_CAPI_END_BLOCK

#define PLAYERCOMPONENT_CREATE(TEXTURE, ANCHOR)                                          \
	(SH3Component) {                                                            \
		.Init               = NULL,                                                      \
		.Terminate          = PlayerComponent_Terminate,                                 \
		.Update             = PlayerComponent_Update,                                                      \                                    \
		.isInitialized      = false,                                                     \
		.componentType      = PlayerCOMPONENT_TYPEID,                                    \
		.properties         = PlayerComponent_CreateProperties(TEXTURE, (uint8_t)ANCHOR) \
		.OnCollisionEnter = Player_Component_Collisions \
	}

#endif /* _H3_COMPONENTS_PLAYERCOMPONENT_H_ */
