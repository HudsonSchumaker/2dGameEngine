/*
	Dodoi Lab
	Dodoi Engine
	Hudson Schumaker
*/

#include "Scene.h"

Scene::Scene() {
	this->renderer = Gfx::getInstance()->getRenderer();
    this->camera = { 0, 0, SCREEN_WIDTH, SCREEN_HEIGHT };
}

float Scene::calculateDeltaTime() {
    // If we are too fast, waste some time until we reach the MILLISECS_PER_FRAME
    int timeToWait = Common::MILLISECS_PER_FRAME - (SDL_GetTicks() - millisecsPreviousFrame);
    if (timeToWait > 0 && timeToWait <= Common::MILLISECS_PER_FRAME) {
        SDL_Delay(timeToWait);
    }

    // The difference in ticks since the last frame, converted to seconds
    deltaTime = (SDL_GetTicks() - millisecsPreviousFrame) / 1000.0f;

    // Store the "previous" frame time
    millisecsPreviousFrame = SDL_GetTicks();

    return deltaTime;
}

void Scene::beginRender() {
    SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255);
	SDL_RenderClear(renderer);
}
	
void Scene::endRender() {
    SDL_RenderPresent(renderer);
}
