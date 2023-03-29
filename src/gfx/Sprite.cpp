/*
	SchumakerTeam
	Hudson Schumaker
*/

#include "Gfx.h"
#include "Sprite.h"
#include "AssetManager.h"
#include "../ecs/EntityManager.h"
#include "../ecs/component/Transform.h"

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

void Sprite::setOnCenter() {
	auto parent = EntityManager::getInstance()->getEntity(parentId);
	auto transform = parent->getComponent<Transform>();
	if (transform) {
		auto bounds = Gfx::getInstance()->getTextureSize(texture);

		transform->position.x = SCREEN_H_WIDTH - (bounds.x/2);
		transform->position.y = SCREEN_H_HEIGHT - (bounds.y/2);
	}
}

void Sprite::setOnCenterX() {
	auto parent = EntityManager::getInstance()->getEntity(parentId);
	auto transform = parent->getComponent<Transform>();
	if (transform) {
		auto bounds = Gfx::getInstance()->getTextureSize(texture);

		transform->position.x = SCREEN_H_WIDTH - (bounds.x/2);
	}
}

void Sprite::setOnCenterY() {
	auto parent = EntityManager::getInstance()->getEntity(parentId);
	auto transform = parent->getComponent<Transform>();
	if (transform) {
		auto bounds = Gfx::getInstance()->getTextureSize(texture);

		transform->position.y = SCREEN_H_HEIGHT - (bounds.y/2);
	}
}

bool Sprite::compareAsc(Entity* e1, Entity* e2) {
	return (e1->getComponent<Sprite>()->layer < e2->getComponent<Sprite>()->layer);
}

bool Sprite::compareDesc(Entity* e1, Entity* e2) {
	return (e1->getComponent<Sprite>()->layer > e2->getComponent<Sprite>()->layer);
}
