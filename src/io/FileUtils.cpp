/*
	SchumakerTeam
	Dodoi Engine
	Hudson Schumaker
*/

#include "FileUtils.h"

std::string FileUtils::getClearName(std::filesystem::path file) {
    return file.stem().string();
}

std::string FileUtils::getClearName(const std::string path) {
    return getClearName(std::filesystem::path(path));
}

std::string FileUtils::getName(const std::string path) {
    std::filesystem::path file(path);
    return file.filename().string();
}

std::string FileUtils::getClearPath(const std::string path) {
    std::size_t pos = path.find_last_of(std::filesystem::path::preferred_separator);
    return path.substr(0, pos + 1);
}

std::string FileUtils::getFileExtension(std::filesystem::path file) {
    return getFileExtension(file.string());
}

std::string FileUtils::getFileExtension(const std::string fileName) {
    std::size_t pos = fileName.find_last_of(".");
    if (pos != std::string::npos)
    {
        return fileName.substr(pos + 1);
    }
    return "";
}

std::vector<std::string> FileUtils::listImageFilesInFolder() {
    const std::set<std::string> imageExtensions = {".jpg", ".jpeg", ".png", ".bmp", ".gif"};
    return listFilesInFolder(IMAGE_FOLDER, imageExtensions);
}

std::vector<std::string> FileUtils::listAudioFilesInFolder() {
    const std::set<std::string> soundExtensions = {".mp3", ".wav", ".ogg"};
    return listFilesInFolder(AUDIO_FOLDER, soundExtensions);
}

std::vector<std::string> FileUtils::listFilesInFolder(const std::filesystem::path dirPath, const std::set<std::string> &extensions) {
    std::vector<std::string> fileNames;

    for (const auto &entry : std::filesystem::directory_iterator(dirPath)) {
        if (entry.is_regular_file()) {
            std::string extension = entry.path().extension().string();
            if (extensions.find(extension) != extensions.end()) {
                fileNames.push_back(entry.path().filename().string());
            }
        }
    }

    return fileNames;
}
