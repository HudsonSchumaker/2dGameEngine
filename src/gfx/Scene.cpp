/*
    Windows 10 - 11
    SchumakerTeam
    Hudson Schumaker
*/

#include "Scene.h"

Scene::Scene() {
	this->renderer = Gfx::getInstance()->getRenderer();
    this->camera = { 0, 0, SCREEN_WIDTH,SCREEN_HEIGHT };
}