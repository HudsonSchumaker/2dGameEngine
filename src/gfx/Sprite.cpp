/*
	Windows 10 - 11
	SchumakerTeam
	Hudson Schumaker
*/

#include "Gfx.h"
#include "Sprite.h"
#include "AssetManager.h"

Sprite::Sprite(short id) {
	texture = AssetManager::getInstance()->getTexture(id);
	rect = Gfx::getInstance()->getTextureFBounds(texture);
	w = rect.w;
	h = rect.h;
}

Sprite::Sprite(short id, short layer) {
	texture = AssetManager::getInstance()->getTexture(id);
	rect = Gfx::getInstance()->getTextureFBounds(texture);
	w = rect.w;
	h = rect.h;
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
