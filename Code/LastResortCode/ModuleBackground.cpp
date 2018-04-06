#include "Globals.h"
#include "Application.h"
#include "ModuleTextures.h"
#include "ModuleRender.h"
#include "ModuleBackground.h"
#include "SDL_image\include\SDL_image.h"
#include <stdlib.h>
#include <time.h> //Asure that we can use this library

#define midgndLoopDist 512 //midgndLoopDist = Distance when the first building on the tilemap repeats
#define midgndOffset 32
#define midgndSpeed 0.4f
#define bckgndSpeed 0.25f
#define foregndSpeed 1.00f
#define tunnelLightDist 256

#define streetLightDist 64
#define roadLightDist 121

// Reference at https://www.youtube.com/watch?v=OEhmUuehGOA

ModuleBackground::ModuleBackground()
{
	//TileMaplvl1
	ground.x = 0;
	ground.y = 0; 
	ground.w = 4408;
	ground.h = 239;

	PBuildings.h = 160;
	PBuildings.w = 1303;
	PBuildings.x = 0;
	PBuildings.y = 0; 

	BGBuildings.x = 0;
	BGBuildings.y = 0;
	BGBuildings.w = 304;
	BGBuildings.h = 176;

	//Tunnel lights
	tunnelLightsAnim.PushBack({   1,   1, 116, 168 });
	tunnelLightsAnim.PushBack({ 118,   1, 116, 168 });
	tunnelLightsAnim.PushBack({ 235,   1, 116, 168 });
	tunnelLightsAnim.PushBack({ 352,   1, 116, 168 });
	tunnelLightsAnim.PushBack({   1, 169, 116, 168 });
	tunnelLightsAnim.PushBack({ 118, 169, 116, 168 });
	tunnelLightsAnim.PushBack({ 235, 169, 116, 168 });
	tunnelLightsAnim.PushBack({ 352, 169, 116, 168 });
	tunnelLightsAnim.speed = 0.08f;

	//Background lights
	//1
	bckgndLightsAnim01.PushBack({   1,  1, 89, 78 });
	bckgndLightsAnim01.PushBack({  91,  1, 89, 78 });
	bckgndLightsAnim01.PushBack({ 181,  1, 89, 78 });
	bckgndLightsAnim01.PushBack({ 271,  1, 89, 78 });
	bckgndLightsAnim01.PushBack({ 361,  1, 89, 78 });
	bckgndLightsAnim01.PushBack({   1, 80, 89, 78 });
	bckgndLightsAnim01.PushBack({  91, 80, 89, 78 });
	bckgndLightsAnim01.PushBack({ 181, 80, 89, 78 });
	bckgndLightsAnim01.speed = 0.08f;
	//2
	bckgndLightsAnim02.PushBack({ 271, 80, 12, 16 });
	bckgndLightsAnim02.PushBack({ 284, 80, 12, 16 });
	bckgndLightsAnim02.PushBack({ 297, 80, 12, 16 });
	bckgndLightsAnim02.PushBack({ 310, 80, 12, 16 });
	bckgndLightsAnim02.PushBack({ 323, 80, 12, 16 });
	bckgndLightsAnim02.PushBack({ 336, 80, 12, 16 });
	bckgndLightsAnim02.PushBack({ 349, 80, 12, 16 });
	bckgndLightsAnim02.PushBack({ 362, 80, 12, 16 });
	bckgndLightsAnim02.speed = 0.08f;
	//3
	bckgndLightsAnim03.PushBack({   1, 161, 64, 75 });
	bckgndLightsAnim03.PushBack({  66, 161, 64, 75 });
	bckgndLightsAnim03.PushBack({ 131, 161, 64, 75 });
	bckgndLightsAnim03.PushBack({ 197, 161, 64, 75 });
	bckgndLightsAnim03.PushBack({ 261, 161, 64, 75 });
	bckgndLightsAnim03.PushBack({ 326, 161, 64, 75 });
	bckgndLightsAnim03.PushBack({ 391, 161, 64, 75 });
	bckgndLightsAnim03.PushBack({   1, 239, 64, 75 });
	bckgndLightsAnim03.speed = 0.08f;
	//4
	bckgndLightsAnim04.PushBack({   1, 315, 167, 89 });
	bckgndLightsAnim04.PushBack({ 169, 315, 167, 89 });
	bckgndLightsAnim04.PushBack({ 337, 315, 167, 89 });
	bckgndLightsAnim04.PushBack({   1, 405, 167, 89 });
	bckgndLightsAnim04.PushBack({ 169, 405, 167, 89 });
	bckgndLightsAnim04.PushBack({ 337, 405, 167, 89 });
	bckgndLightsAnim04.PushBack({   1, 495, 167, 89 });
	bckgndLightsAnim04.PushBack({ 169, 495, 167, 89 });
	bckgndLightsAnim04.speed = 0.08f;
	//5
	bckgndLightsAnim05.PushBack({   1, 585, 31, 58 });
	bckgndLightsAnim05.PushBack({  33, 585, 31, 58 });
	bckgndLightsAnim05.PushBack({  65, 585, 31, 58 });
	bckgndLightsAnim05.PushBack({  97, 585, 31, 58 });
	bckgndLightsAnim05.PushBack({ 129, 585, 31, 58 });
	bckgndLightsAnim05.PushBack({ 161, 585, 31, 58 });
	bckgndLightsAnim05.PushBack({ 193, 585, 31, 58 });
	bckgndLightsAnim05.PushBack({ 255, 585, 31, 58 });
	bckgndLightsAnim05.speed = 0.08f;
	//6
	bckgndLightsAnim06.PushBack({   1, 644, 47, 51 });
	bckgndLightsAnim06.PushBack({  49, 644, 47, 51 });
	bckgndLightsAnim06.PushBack({  97, 644, 47, 51 });
	bckgndLightsAnim06.PushBack({ 145, 644, 47, 51 });
	bckgndLightsAnim06.PushBack({ 193, 644, 47, 51 });
	bckgndLightsAnim06.PushBack({ 241, 644, 47, 51 });
	bckgndLightsAnim06.PushBack({ 289, 644, 47, 51 });
	bckgndLightsAnim06.PushBack({ 337, 644, 47, 51 });
	bckgndLightsAnim06.speed = 0.08f;

	//Midground lights
	//1
	midgndLightsAnim01.PushBack({   1, 1, 95, 86 });
	midgndLightsAnim01.PushBack({  98, 1, 95, 86 });
	midgndLightsAnim01.PushBack({ 195, 1, 95, 86 });
	midgndLightsAnim01.PushBack({ 292, 1, 95, 86 });
	midgndLightsAnim01.PushBack({ 389, 1, 95, 86 });
	midgndLightsAnim01.PushBack({ 486, 1, 95, 86 });
	midgndLightsAnim01.PushBack({ 583, 1, 95, 86 });
	midgndLightsAnim01.speed = 0.08f;
	//2
	midgndLightsAnim02.PushBack({   1, 88, 37, 61 });
	midgndLightsAnim02.PushBack({  39, 88, 37, 61 });
	midgndLightsAnim02.PushBack({  77, 88, 37, 61 });
	midgndLightsAnim02.PushBack({ 115, 88, 37, 61 });
	midgndLightsAnim02.PushBack({ 153, 88, 37, 61 });
	midgndLightsAnim02.PushBack({ 191, 88, 37, 61 });
	midgndLightsAnim02.PushBack({ 229, 88, 37, 61 });
	midgndLightsAnim02.speed = 0.08f;
	//3
	midgndLightsAnim03.PushBack({   1, 150, 108, 47 });
	midgndLightsAnim03.PushBack({ 110, 150, 108, 47 });
	midgndLightsAnim03.PushBack({ 219, 150, 108, 47 });
	midgndLightsAnim03.PushBack({ 328, 150, 108, 47 });
	midgndLightsAnim03.PushBack({ 437, 150, 108, 47 });
	midgndLightsAnim03.PushBack({ 546, 150, 108, 47 });
	midgndLightsAnim03.PushBack({ 655, 150, 108, 47 });
	midgndLightsAnim03.speed = 0.08f;
	//4
	midgndLightsAnim04.PushBack({   1, 198, 15, 12 });
	midgndLightsAnim04.PushBack({  17, 198, 15, 12 });
	midgndLightsAnim04.PushBack({  33, 198, 15, 12 });
	midgndLightsAnim04.PushBack({  49, 198, 15, 12 });
	midgndLightsAnim04.PushBack({  65, 198, 15, 12 });
	midgndLightsAnim04.PushBack({  81, 198, 15, 12 });
	midgndLightsAnim04.PushBack({  97, 198, 15, 12 });
	midgndLightsAnim04.speed = 0.08f;
	//5
	midgndLightsAnim05.PushBack({   1, 211, 48, 93 });
	midgndLightsAnim05.PushBack({  50, 211, 48, 93 });
	midgndLightsAnim05.PushBack({  99, 211, 48, 93 });
	midgndLightsAnim05.PushBack({ 148, 211, 48, 93 });
	midgndLightsAnim05.PushBack({ 197, 211, 48, 93 });
	midgndLightsAnim05.PushBack({ 246, 211, 48, 93 });
	midgndLightsAnim05.PushBack({ 295, 211, 48, 93 });
	midgndLightsAnim05.speed = 0.08f;
	//6
	midgndLightsAnim06.PushBack({   1, 305, 61, 77 });
	midgndLightsAnim06.PushBack({  63, 305, 61, 77 });
	midgndLightsAnim06.PushBack({ 125, 305, 61, 77 });
	midgndLightsAnim06.PushBack({ 187, 305, 61, 77 });
	midgndLightsAnim06.PushBack({ 249, 305, 61, 77 });
	midgndLightsAnim06.PushBack({ 311, 305, 61, 77 });
	midgndLightsAnim06.PushBack({ 373, 305, 61, 77 });
	midgndLightsAnim06.speed = 0.08f;
	//!TO IMPLEMENT: Adjust animation speed

	//Street Lights
	//1
	streetLightsAnim01.PushBack({ 0,0, 48, 65 });
	streetLightsAnim01.PushBack({ 49, 0, 48, 65 });
	streetLightsAnim01.PushBack({ 98, 0, 48, 65 });
	streetLightsAnim01.PushBack({ 147, 0, 48, 65 });
	streetLightsAnim01.PushBack({ 98, 0, 48, 65 });
	streetLightsAnim01.PushBack({ 49, 0, 48, 65 });
	streetLightsAnim01.speed = 0.10f;
	//2
	streetLightsAnim02.PushBack({ 0,66, 61, 20 });
	streetLightsAnim02.PushBack({ 62,66, 61, 20 });
	streetLightsAnim02.PushBack({ 124,66, 61, 20 });
	streetLightsAnim02.PushBack({ 186,66, 61, 20 });
	streetLightsAnim02.PushBack({ 0,87, 61, 20 });
	streetLightsAnim02.PushBack({ 186,66, 61, 20 });
	streetLightsAnim02.PushBack({ 124,66, 61, 20 });
	streetLightsAnim02.PushBack({ 62,66, 61, 20 });

	streetLightsAnim02.speed = 0.10f;
}





ModuleBackground::~ModuleBackground()
{}

// Load assets
bool ModuleBackground::Start()
{
	LOG("Loading background assets");
	bool ret = true;
	groundAndTunel = App->textures->Load("Assets/TileMaplvl1Ground&Tunel.png");
	PurpleBuildings = App->textures->Load("Assets/midGroundBuildingsFull.png");
	BackgroundBuildings = App->textures->Load("Assets/firstCameraMovBuilding04.png");

	Boss1Background = App->textures->Load("Assets/StaticBackground.png");
	bckgndLightsTx = App->textures->Load("Assets/BackgroundLights.png");
	midgndLightsTx = App->textures->Load("Assets/MidgroundLights.png");
	tunnelLightsTx = App->textures->Load("Assets/TunnelLights.png");
	streetLightsTx = App->textures->Load("Assets/StreetLights.png");

	srand(time(NULL));

	for (int i = 1; i < 27; ++i) {
		randoms[i] = rand() % 6 + 1;
	}
	return ret;
}



// Update: draw background
update_status ModuleBackground::Update()
{
	//Boss buildings
	if (App->render->camera.x < -2320) {
		
		App->render->Blit(Boss1Background, 0, 0, NULL, 0.0f);
	}

	//Background buildings
	else if (App->render->camera.x > -2820) {
		App->render->Blit(BackgroundBuildings, 0, 0, &BGBuildings, 0.0f);
	} //-2820 and -2320 change


	//Background lights
	//App->render->Blit(bckgndLightsTx, , , &bckgndLightsAnim01.GetCurrentFrame(), bckgndSpeed);
	//App->render->Blit(bckgndLightsTx, , , &bckgndLightsAnim02.GetCurrentFrame(), bckgndSpeed);
	//App->render->Blit(bckgndLightsTx, , , &bckgndLightsAnim03.GetCurrentFrame(), bckgndSpeed);
	//App->render->Blit(bckgndLightsTx, , , &bckgndLightsAnim04.GetCurrentFrame(), bckgndSpeed);
	//App->render->Blit(bckgndLightsTx, , , &bckgndLightsAnim05.GetCurrentFrame(), bckgndSpeed);
	//App->render->Blit(bckgndLightsTx, , , &bckgndLightsAnim06.GetCurrentFrame(), bckgndSpeed);
	//Midground buildings
	App->render->Blit(PurpleBuildings, 0, midgndOffset, &PBuildings, midgndSpeed);
	//Midground lights
	//- Loop 1
	App->render->Blit(midgndLightsTx,  40, midgndOffset + 28, &midgndLightsAnim01.GetCurrentFrame(), midgndSpeed);
	App->render->Blit(midgndLightsTx, 184, midgndOffset + 18, &midgndLightsAnim02.GetCurrentFrame(), midgndSpeed);
	App->render->Blit(midgndLightsTx, 234, midgndOffset + 97, &midgndLightsAnim03.GetCurrentFrame(), midgndSpeed);
	App->render->Blit(midgndLightsTx, 329, midgndOffset +  2, &midgndLightsAnim04.GetCurrentFrame(), midgndSpeed);
	App->render->Blit(midgndLightsTx, 392, midgndOffset + 50, &midgndLightsAnim05.GetCurrentFrame(), midgndSpeed);
	App->render->Blit(midgndLightsTx, 471, midgndOffset + 36, &midgndLightsAnim06.GetCurrentFrame(), midgndSpeed);
	//- Loop 2
	App->render->Blit(midgndLightsTx, midgndLoopDist +  40, midgndOffset + 28, &midgndLightsAnim01.GetCurrentFrame(), midgndSpeed);
	App->render->Blit(midgndLightsTx, midgndLoopDist + 184, midgndOffset + 18, &midgndLightsAnim02.GetCurrentFrame(), midgndSpeed);
	App->render->Blit(midgndLightsTx, midgndLoopDist + 234, midgndOffset + 97, &midgndLightsAnim03.GetCurrentFrame(), midgndSpeed);
	App->render->Blit(midgndLightsTx, midgndLoopDist + 329, midgndOffset +  2, &midgndLightsAnim04.GetCurrentFrame(), midgndSpeed);
	App->render->Blit(midgndLightsTx, midgndLoopDist + 392, midgndOffset + 50, &midgndLightsAnim05.GetCurrentFrame(), midgndSpeed);
	App->render->Blit(midgndLightsTx, midgndLoopDist + 471, midgndOffset + 36, &midgndLightsAnim06.GetCurrentFrame(), midgndSpeed);
	//- Loop 3
	App->render->Blit(midgndLightsTx, midgndLoopDist * 2 +  40, midgndOffset + 28, &midgndLightsAnim01.GetCurrentFrame(), midgndSpeed);
	App->render->Blit(midgndLightsTx, midgndLoopDist * 2 + 184, midgndOffset + 18, &midgndLightsAnim02.GetCurrentFrame(), midgndSpeed);
	App->render->Blit(midgndLightsTx, midgndLoopDist * 2 + 234, midgndOffset + 97, &midgndLightsAnim03.GetCurrentFrame(), midgndSpeed);
	App->render->Blit(midgndLightsTx, midgndLoopDist * 2 + 329, midgndOffset +  2, &midgndLightsAnim04.GetCurrentFrame(), midgndSpeed);
	App->render->Blit(midgndLightsTx, midgndLoopDist * 2 + 392, midgndOffset + 50, &midgndLightsAnim05.GetCurrentFrame(), midgndSpeed);
	App->render->Blit(midgndLightsTx, midgndLoopDist * 2 + 471, midgndOffset + 36, &midgndLightsAnim06.GetCurrentFrame(), midgndSpeed);
	//Positions calculated from the png


	//Ground and tunnel
	App->render->Blit(groundAndTunel, 0, 0, &ground, foregndSpeed);

	//Street Lights
	//1
	App->render->Blit(streetLightsTx, 40 , 136, &streetLightsAnim01.GetCurrentFrame(), 1.0f);
	for (int i = 1; i < 27; ++i) {
		App->render->Blit(streetLightsTx, 40 + streetLightDist *i, 136, &streetLightsAnim01.GetFrame(randoms[i]), 1.0f);
	}
	//2
	App->render->Blit(streetLightsTx, 0, 217, &streetLightsAnim02.GetCurrentFrame(), 1.0f);
	for (int i = 1; i < 14; ++i) {
		App->render->Blit(streetLightsTx, 0 + roadLightDist * i, 217, &streetLightsAnim02.GetFrame(randoms[i]), 1.0f);
	}
	
	//Tunnel lights
	App->render->Blit(tunnelLightsTx, 2048 + tunnelLightDist * 0, 0, &tunnelLightsAnim.GetCurrentFrame(), foregndSpeed);
	App->render->Blit(tunnelLightsTx, 2048 + tunnelLightDist * 1, 0, &tunnelLightsAnim.GetCurrentFrame(), foregndSpeed);
	App->render->Blit(tunnelLightsTx, 2048 + tunnelLightDist * 2, 0, &tunnelLightsAnim.GetCurrentFrame(), foregndSpeed);
	App->render->Blit(tunnelLightsTx, 2048 + tunnelLightDist * 3, 0, &tunnelLightsAnim.GetCurrentFrame(), foregndSpeed);
	App->render->Blit(tunnelLightsTx, 2048 + tunnelLightDist * 4, 0, &tunnelLightsAnim.GetCurrentFrame(), foregndSpeed);
	App->render->Blit(tunnelLightsTx, 2048 + tunnelLightDist * 5, 0, &tunnelLightsAnim.GetCurrentFrame(), foregndSpeed);
	App->render->Blit(tunnelLightsTx, 2048 + tunnelLightDist * 6, 0, &tunnelLightsAnim.GetCurrentFrame(), foregndSpeed);
	App->render->Blit(tunnelLightsTx, 2048 + tunnelLightDist * 7, 0, &tunnelLightsAnim.GetCurrentFrame(), foregndSpeed);
	//Could be implemented with a for, but probably all the frames would be the same
	//2048 = distance from the start of the tilemap to the first light
	
	return UPDATE_CONTINUE;
}