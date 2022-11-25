#include "playercomponent.h"
#include <stdlib.h>

typedef struct
{
	int bip;
} PlayerComponent_Properties;

void PlayerComponent_Terminate(void* properties)
{
	free(properties);
}

void PlayerComponent_Update(H3Handle h3, H3Handle object, void* properties) {
	PlayerComponent_Properties* props = (PlayerComponent_Properties*)properties;
}

void* PlayerComponent_CreateProperties()
{
	PlayerComponent_Properties* properties = malloc(sizeof(PlayerComponent_Properties));
	H3_ASSERT_CONSOLE(properties, "Failed to allocate properties");

	return properties;
}

void Player_Component_Collisions(H3Handle object, SH3Collision collisions) {
	//if (H3_Object_HasComponent(collisions.other, ))
}
