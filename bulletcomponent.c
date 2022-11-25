#include "bulletcomponent.h"
#include <stdlib.h>

typedef struct
{
	int bip;
} BulletComponent_Properties;

void BulletComponent_Terminate(void* properties)
{
	free(properties);
}

void BulletComponent_Update(H3Handle h3, H3Handle object, void* properties) {
	BulletComponent_Properties* props = (BulletComponent_Properties*)properties;
}

void* BulletComponent_CreateProperties()
{
	BulletComponent_Properties* properties = malloc(sizeof(BulletComponent_Properties));
	H3_ASSERT_CONSOLE(properties, "Failed to allocate properties");

	return properties;
}

void Bullet_Component_Collisions(H3Handle object, SH3Collision collisions) {
	if (H3_Object_HasComponent(collisions.other, 0x80000001)) {
		H3_Object_Destroy(&object, true);
	}
}
