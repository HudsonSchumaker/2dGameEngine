/*
	SchumakerTeam
	Hudson Schumaker
*/

#include "AudioManager.h"

AudioManager::AudioManager() {}
AudioManager::~AudioManager() {
	clearAssets();
}

AudioManager* AudioManager::getInstance() {
	if (instance == nullptr) {
		instance = new AudioManager();
	}

	return instance;
}

void AudioManager::addSound(const short assetId, const std::string& filePath) {
	this->sounds.emplace(assetId, Mix_LoadWAV(filePath.c_str()));
}

void AudioManager::playSound(short assetId) {
	std::async(std::launch::async, [&]() {
		Mix_PlayChannel(-1, this->sounds[assetId], 0);
	});
}

void AudioManager::clearAssets() {
	for (auto& sound : sounds) {
		Mix_FreeChunk(sound.second);
	}
}

void AudioManager::load() {
	addSound(AudioManager::OK, "data/audio/ok.wav");
	addSound(AudioManager::BACK, "data/audio/back.wav");

	std::cout << "done load audios" << std::endl;
}