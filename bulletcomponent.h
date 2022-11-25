#ifndef _H3_COMPONENTS_BULLETCOMPONENT_H_
#define _H3_COMPONENTS_BULLETCOMPONENT_H_

#include <h3.h>

#define BULLETCOMPONENT_TYPEID 0x70000001

H3_CAPI_BEGIN_BLOCK
void BulletComponent_Terminate(void* properties);
void BulletComponent_Update(H3Handle h3, SH3Transform* transform, void* properties);

void* BulletComponent_CreateProperties(const char* texturePath, uint8_t anchor);
void Bullet_Component_Collisions(H3Handle Object, SH3Collision collisions);
H3_CAPI_END_BLOCK

#define BULLETCOMPONENT_CREATE(TEXTURE, ANCHOR)                                          \
	(SH3Component) {                                                            \
		.Init               = NULL,                                                      \
		.Terminate          = BulletComponent_Terminate,                                 \
		.Update             = BulletComponent_Update,                                                      \                                    \
		.isInitialized      = false,                                                     \
		.componentType      = BULLETCOMPONENT_TYPEID,                                    \
		.properties         = BulletComponent_CreateProperties(TEXTURE, (uint8_t)ANCHOR) \
		.OnCollisionEnter = Bullet_Component_Collisions \
	}

#endif /* _H3_COMPONENTS_BULLETCOMPONENT_H_ */
