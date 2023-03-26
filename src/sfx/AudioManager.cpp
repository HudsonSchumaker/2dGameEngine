/*
	SchumakerTeam
	Hudson Schumaker
*/

#include "AudioManager.h"
#include "../io/FileUtils.h"

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

void AudioManager::addSound(const std::string& name, const std::string& filePath) {
	this->sounds.emplace(name, Mix_LoadWAV(filePath.c_str()));
}

void AudioManager::playSound(const std::string&name) {
	std::async(std::launch::async, [&]() {
		Mix_PlayChannel(-1, this->sounds[name], 0);
	});
}

void AudioManager::clearAssets() {
	for (auto& sound : sounds) {
		Mix_FreeChunk(sound.second);
	}
}

void AudioManager::load() {
	auto files = FileUtils::listAudioFilesInFolder();
    for (auto& file : files) {
        auto filePath = AUDIO_FOLDER + file;
        addSound(FileUtils::getClearName(filePath), filePath);
    }

	std::cout << "done load audios" << std::endl;
}