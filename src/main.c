#include <h3.h>
#include "components\spritecomponent.h"
#include "components\cameracomponent.h"
#include <stdlib.h>
#include<math.h>

#ifndef NDEBUG
# pragma comment(lib, "h3-s-d.lib")
#else // !NDEBUG
# pragma comment(lib, "h3-s.lib")
#endif // !NDEBUG

int width;
int height;

int main(int argc, char** argv)
{
	width = 1280;
	height = 720;




	H3Handle h3 = H3_Init((SH3InitParams) {
		.fullscreen = false,
			.height = height,
			.width = width,
			.windowTitle = "Worms like Hydrogen Engine 3"
	});


	H3Handle scene = H3_Scene_Create(h3, true);
	H3Handle player = H3_Object_Create(scene, "player", NULL);
	H3Handle ennemy = H3_Object_Create(scene, "ennemy", NULL);
	H3Handle mapsolid = H3_Object_Create(scene, "mapsolid", NULL);


	H3_Object_AddComponent(mapsolid, SPRITECOMPONENT_CREATE("assets/wormsmap.png", 0x22));
	H3_Object_SetRenderOrder(mapsolid, 1);
	H3_Object_Translate(mapsolid, 650, 314);
	H3_Object_Scale(mapsolid, 2.5);


	H3_Object_AddComponent(player, SPRITECOMPONENT_CREATE("assets/Player.png", 0x22));
	H3_Object_SetRenderOrder(player, 2);
	H3_Object_Translate(player, 100, 200);
	

	H3_Object_AddComponent(ennemy, SPRITECOMPONENT_CREATE("assets/Player.png", 0x22));
	H3_Object_SetRenderOrder(ennemy, 2);
	H3_Object_Translate(ennemy, width/2, height/2);




	while (H3_DoFrame(h3, scene)) {

	}
	return 0;
}
