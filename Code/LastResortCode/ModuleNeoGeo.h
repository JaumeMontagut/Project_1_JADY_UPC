#ifndef __MODULENEOGEO_H__
#define __MODULENEOGEO_H__

#include "Module.h"
#include "Animation.h"
#include "Globals.h"

#define NEOGEOWIDTH 227

struct SDL_Texture;

class ModuleNeoGeo : public Module
{
public:
	ModuleNeoGeo();
	~ModuleNeoGeo();

	bool Start();
	update_status Update();
	bool CleanUp();

public:

	SDL_Texture * neogeoTx = nullptr;
	SDL_Rect neogeoRect;
	Animation neogeoAnim;
	float neogeoAnimSpeed = 0.5f;

	SDL_Rect proGearSpecRect;

	//SDL_Texture * snkTx = nullptr;
	//SDL_Texture * proGearSpecTx = nullptr;
	//SDL_Rect snkRect;

	int currentFade = 255;
};

#endif // __MODULENEOGEO_H__
