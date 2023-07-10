/*
	SchumakerTeam
	Dodoi Engine
	Hudson Schumaker
*/

#include "Gfx.h"
#include "Animation.h"
#include "AssetManager.h"

Animation::Animation(const std::string& name, short numFrames, int frameSpeedRate, bool isLoop) {
	this->numFrames = numFrames;
	this->frameSpeedRate = frameSpeedRate;
	this->isLoop = isLoop;

	texture = AssetManager::getInstance()->getTexture(name);
	bounds = Gfx::getInstance()->getTextureSize(texture);
	bounds.x = bounds.x / numFrames;
	startTime = SDL_GetTicks();
}

Animation::Animation(const std::string& name, short numFrames, int frameSpeedRate, short layer, bool isLoop) {
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

Dimension Animation::getSize() const {
	return Dimension(bounds.x, bounds.y);
}

bool Animation::compareAsc(Entity* e1, Entity* e2) {
	return (e1->getComponent<Animation>()->layer < e2->getComponent<Animation>()->layer);
}

bool Animation::compareDesc(Entity* e1, Entity* e2) {
	return (e1->getComponent<Animation>()->layer > e2->getComponent<Animation>()->layer);
}
