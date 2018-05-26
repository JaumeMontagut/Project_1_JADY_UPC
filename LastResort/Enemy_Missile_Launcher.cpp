#include "Enemy_Missile_Launcher.h"
#include "Application.h"
#include "ModuleStage05.h"
#include "ModuleEnemies.h"
Enemy_Missile_Launcher::Enemy_Missile_Launcher(int x, int y, float hp, int scoreValue, POWERUP_TYPE powerupDrop) :Enemy ( x,  y,  hp,  scoreValue, powerupDrop)
{
	Missile_Launcher.PushBack({ 250,278,29,32 });
	Missile_Launcher.speed = 0.0f;
	animation = &Missile_Launcher;
	collider = App->collision->AddCollider({ x, y, 29, 32 }, COLLIDER_TYPE::COLLIDER_ENEMY_LIGHT, (Module*)App->enemies);

}
void Enemy_Missile_Launcher::Move() {
	position = fixedPos + App->stage05->spawnPos;

	if (frameCount == 150 /*&& position.x>0*/ && position. y>0)
	{
		App->enemies->AddEnemy(MISSILE,fixedPos.x+100, fixedPos.y + 10);
 		frameCount = 0;
	}


	frameCount += 1;
}