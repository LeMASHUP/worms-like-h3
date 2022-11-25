#include <h3.h>
#include "components\spritecomponent.h"
#include "components\cameracomponent.h"
#include "components\maplayercomponent.h"
#include <stdlib.h>
#include <conio.h>
#include<math.h>
#include "components/playercomponent.h"
#include "components/bulletcomponent.h"

#ifndef NDEBUG
# pragma comment(lib, "h3-s-d.lib")
#else // !NDEBUG
# pragma comment(lib, "h3-s.lib")
#endif // !NDEBUG

int width;
int height;
int playerlife;
int ennemylife;
float playerx;
float playery;
int mousex;
int mousey;
int turn;
int shootturn;
float dx;
float dy;
float bx;
float by;
turn = 5;
shootturn = 10000;


int main(int argc, char** argv)
{
	width = 1280;
	height = 720;

	char bullet_name[15];
	int index_bullet = 0;




	H3Handle h3 = H3_Init((SH3InitParams) {
		.fullscreen = false,
			.height = height,
			.width = width,
			.windowTitle = "Worms like Hydrogen Engine 3"

	});


	H3Handle scene = H3_Scene_Create(h3, true);
	H3Handle player = H3_Object_Create(scene, "player", NULL);
	H3Handle ennemy = H3_Object_Create(scene, "ennemy", NULL);
	H3Handle bullet = H3_Object_Create(scene, "bullet", NULL);


	H3_Object_AddComponent(player, SPRITECOMPONENT_CREATE("assets/Player.png", 0x22));
	H3_Object_AddComponent(player, PLAYERCOMPONENT_CREATE());
	H3_Object_EnablePhysics(player, H3_BOX_COLLIDER(CDT_Dynamic, 32, 64, 0x22, false));
	H3_Object_SetRenderOrder(player, 2);
	H3_Object_SetTranslation(player, 300, 50);


	H3_Object_AddComponent(ennemy, SPRITECOMPONENT_CREATE("assets/ennemy.png", 0x22));
	H3_Object_EnablePhysics(ennemy, H3_BOX_COLLIDER(CDT_Dynamic, 32, 64, 0x22, false));
	H3_Object_SetRenderOrder(ennemy, 3);
	H3_Object_SetTranslation(ennemy, 870, 50);




	H3Handle accueil_worms = H3_Map_Load("assets/1worms.tmx"); // une sorte d'accès à ta map (n'est pas la map dans la scène, la charge uniquement)
	H3Handle map1 = H3_Object_Create(scene, "map1", NULL); //Crée la map dans la scène -> différent d'en haut qui load uniquement (celle ci va permettre de la place dans la scène)
	H3_Object_AddComponent(map1, MAPLAYERCOMPONENT_CREATE(accueil_worms, "background")); //Comme pour les collisions, sauf qu'ici tu appelles un composant pour afficher ton layer décoratif (fond et sol du jeu)
	H3_Map_RegisterObjectLayerForPhysicsInScene(scene, accueil_worms, "collisions"); //dans ta map Tiled tu as des layers, dont un qui doit s'appeler collisions (celui que tu appelles du coup)


	while (H3_DoFrame(h3, scene)) {
		H3_Input_GetMousePos(h3, &mousex, &mousey);
		H3_Transform_GetPosition(H3_Object_GetTransform(player), &playerx, &playery);
		dy = mousey - playery;
		dx = mousex - playerx;
		H3_Object_SetVelocity(player, 0, playery * 0.95);
		H3_Object_SetVelocity(ennemy, 0, playery * 0.95);

		int num;




		if (shootturn > 0) {
			if (H3_Input_IsMouseBtnPressed(MB_Right)) {
				snprintf(bullet_name, 15, "%d", index_bullet++);
				H3Handle bullet = H3_Object_Create(scene, bullet_name, NULL);
				H3_Object_EnablePhysics(bullet, H3_BOX_COLLIDER(CDT_Dynamic, 5, 5, 0x22, false));
				H3_Object_SetTranslation(bullet, playerx, playery);
				H3_Object_AddComponent(bullet, SPRITECOMPONENT_CREATE("assets/bomb.png", A_Center));
				H3_Object_AddComponent(bullet, BULLETCOMPONENT_CREATE());
				H3_Object_AddVelocity(bullet, dx, dy);
				H3_Object_GetVelocity(bullet, &bx, &by);
				H3_Object_SetVelocity(bullet, bx, by);
				shootturn = 0;
				turn = 0;
			}
		}



		if (turn > 0) {

			if (H3_Input_IsKeyPressed(K_Right)) {
				H3_Object_Translate(player, 20, 0);
				turn -= 1;
			}
			if (H3_Input_IsKeyPressed(K_Left)) {
				H3_Object_Translate(player, -20, 0);
				turn -= 1;
			}
			if (H3_Input_IsKeyPressed(K_Up)) {
				H3_Object_Translate(player, 0, -50);
			}
		}
	}
	return 0;
}
