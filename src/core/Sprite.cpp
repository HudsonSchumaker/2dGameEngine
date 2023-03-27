/*
	SchumakerTeam
	Hudson Schumaker
*/

#include "../include/Gfx.h"
#include "../include/Sprite.h"
#include "../include/AssetManager.h"

Sprite::Sprite(const std::string& name) {
	texture = AssetManager::getInstance()->getTexture(name);
	srcRect = Gfx::getInstance()->getTextureBounds(texture);
	w = srcRect.w;
	h = srcRect.h;
}

Sprite::Sprite(const std::string& name, bool isFixed) {
	texture = AssetManager::getInstance()->getTexture(name);
	srcRect = Gfx::getInstance()->getTextureBounds(texture);
	w = srcRect.w;
	h = srcRect.h;
	this->isFixed = isFixed;
}

Sprite::Sprite(const std::string& name, bool isFixed, short layer) {
	texture = AssetManager::getInstance()->getTexture(name);
	srcRect = Gfx::getInstance()->getTextureBounds(texture);
	w = srcRect.w;
	h = srcRect.h;
	this->isFixed = isFixed;
	this->layer = layer;
}

Sprite::Sprite(const std::string& name, short layer) {
	texture = AssetManager::getInstance()->getTexture(name);
	srcRect = Gfx::getInstance()->getTextureBounds(texture);
	w = srcRect.w;
	h = srcRect.h;
	this->layer = layer;
}

Sprite::Sprite(const std::string& name, int srcX, int srcY, int w, int h, short layer) {
	texture = AssetManager::getInstance()->getTexture(name);
	srcRect = {
		srcX,
		srcY,
		w,
		h
	};

	this->w = srcRect.w;
	this->h = srcRect.h;
	this->layer = layer;
}

Sprite::Sprite(const std::string& name, int srcX, int srcY, int w, int h, bool isFixed, short layer) {
	texture = AssetManager::getInstance()->getTexture(name);
	srcRect = {
		srcX,
		srcY,
		w,
		h
	};

	this->w = srcRect.w;
	this->h = srcRect.h;
	this->isFixed = isFixed;
	this->layer = layer;
}

Sprite::~Sprite() {
	if (texture) {
		SDL_DestroyTexture(texture);
	}
}

bool Sprite::compareAsc(Entity* e1, Entity* e2) {
	return (e1->getComponent<Sprite>()->layer < e2->getComponent<Sprite>()->layer);
}

bool Sprite::compareDesc(Entity* e1, Entity* e2) {
	return (e1->getComponent<Sprite>()->layer > e2->getComponent<Sprite>()->layer);
}
