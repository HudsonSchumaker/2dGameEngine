/*
	Windows 10 - 11
	SchumakerTeam
	Hudson Schumaker
*/

#pragma once
#include "Component.h"
#include "../../sfx/AudioManager.h"

class Audio final : public Component {
public:
	short audioId = 0;
	boolean playOnAwake = false;
	boolean loop = false;

	Audio(short audioId) {
		this->audioId = audioId;
	}

	Audio(short audioId, boolean playOnAwake, boolean loop) {
		this->audioId = audioId;
		this->playOnAwake = playOnAwake;
		this->loop = loop;

		if (playOnAwake) { play(); }
	}

	void play() {
		AudioManager::getInstance()->playSound(audioId);
	}
};
