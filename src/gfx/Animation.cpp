/*
	SchumakerTeam
	Hudson Schumaker
*/

#include "Gfx.h"
#include "Animation.h"
#include "AssetManager.h"

Animation::Animation(const std::string& name, short numFrames, short frameSpeedRate, bool isLoop) {
	this->numFrames = numFrames;
	this->frameSpeedRate = frameSpeedRate;
	this->isLoop = isLoop;

	texture = AssetManager::getInstance()->getTexture(name);
	bounds = Gfx::getInstance()->getTextureSize(texture);
	bounds.x = bounds.x / numFrames;
	startTime = SDL_GetTicks();
}

Animation::Animation(const std::string& name, short numFrames, short frameSpeedRate, short layer, bool isLoop) {
	this->numFrames = numFrames;
	this->frameSpeedRate = frameSpeedRate;
	this->layer = layer;
	this->isLoop = isLoop;

	texture = AssetManager::getInstance()->getTexture(name);
	bounds = Gfx::getInstance()->getTextureSize(texture);
	bounds.x = bounds.x / numFrames;
	startTime = SDL_GetTicks();
}

Animation::~Animation() {
	if (texture) {
		SDL_DestroyTexture(texture);
	}
}

bool Animation::compareAsc(Entity* e1, Entity* e2) {
	return (e1->getComponent<Animation>()->layer < e2->getComponent<Animation>()->layer);
}

bool Animation::compareDesc(Entity* e1, Entity* e2) {
	return (e1->getComponent<Animation>()->layer > e2->getComponent<Animation>()->layer);
}