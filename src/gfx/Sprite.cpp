/*
	SchumakerTeam
	Hudson Schumaker
*/

#include "Gfx.h"
#include "Sprite.h"
#include "AssetManager.h"

Sprite::Sprite(short id) {
	texture = AssetManager::getInstance()->getTexture(id);
	srcRect = Gfx::getInstance()->getTextureBounds(texture);
	w = srcRect.w;
	h = srcRect.h;
}

Sprite::Sprite(short id, bool isFixed) {
	texture = AssetManager::getInstance()->getTexture(id);
	srcRect = Gfx::getInstance()->getTextureBounds(texture);
	w = srcRect.w;
	h = srcRect.h;
	this->isFixed = isFixed;
}

Sprite::Sprite(short id, bool isFixed, short layer) {
	texture = AssetManager::getInstance()->getTexture(id);
	srcRect = Gfx::getInstance()->getTextureBounds(texture);
	w = srcRect.w;
	h = srcRect.h;
	this->isFixed = isFixed;
	this->layer = layer;
}

Sprite::Sprite(short id, short layer) {
	texture = AssetManager::getInstance()->getTexture(id);
	srcRect = Gfx::getInstance()->getTextureBounds(texture);
	w = srcRect.w;
	h = srcRect.h;
	this->layer = layer;
}

Sprite::Sprite(short id, int srcX, int srcY, int w, int h, short layer) {
	texture = AssetManager::getInstance()->getTexture(id);
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

Sprite::Sprite(short id, int srcX, int srcY, int w, int h, bool isFixed, short layer) {
	texture = AssetManager::getInstance()->getTexture(id);
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
