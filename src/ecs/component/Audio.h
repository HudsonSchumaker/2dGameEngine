/*
	Dodoi Lab
	Dodoi Engine
	Hudson Schumaker
*/

#pragma once
#include "Component.h"
#include "../../sfx/AudioManager.h"

class Audio final : public Component {
public:
	std::string audioId;
	bool playOnAwake = false;
	bool loop = false;

	Audio(std::string& audioId) {
		this->audioId = audioId;
	}

	Audio(std::string& audioId, bool playOnAwake, bool loop) {
		this->audioId = audioId;
		this->playOnAwake = playOnAwake;
		this->loop = loop;

		if (playOnAwake) { play(); }
	}

	void play() {
		AudioManager::getInstance()->playSound(audioId);
	}
};
