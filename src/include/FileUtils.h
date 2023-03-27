/*
	SchumakerTeam
	Hudson Schumaker
*/

#include "Common.h"

class FileUtils {
public:
    static std::string getClearName(std::filesystem::path file) {
        return file.stem().string();
    }

    static std::string getClearName(const std::string path) {
        return getClearName(std::filesystem::path(path));
    }

    static std::string getName(const std::string path) {
        std::filesystem::path file(path);
        return file.filename().string();
    }

    static std::string getClearPath(const std::string path) {
        std::size_t pos = path.find_last_of(std::filesystem::path::preferred_separator);
        return path.substr(0, pos + 1);
    }

    static std::string getFileExtension(std::filesystem::path file) {
        return getFileExtension(file.string());
    }

    static std::string getFileExtension(const std::string fileName) {
        std::size_t pos = fileName.find_last_of(".");
        if (pos != std::string::npos) {
            return fileName.substr(pos + 1);
        }
        return "";
    }

    static std::vector<std::string> listImageFilesInFolder() {
        const std::set<std::string> imageExtensions = { ".jpg", ".jpeg", ".png", ".bmp", ".gif" };
        return listFilesInFolder(IMAGE_FOLDER, imageExtensions);
    }

    static std::vector<std::string> listAudioFilesInFolder() {
        const std::set<std::string> soundExtensions = { ".mp3", ".wav", ".ogg" };
        return listFilesInFolder(AUDIO_FOLDER, soundExtensions);
    }

    static std::vector<std::string> listFilesInFolder(const std::filesystem::path dirPath, const std::set<std::string>& extensions) {
        std::vector<std::string> fileNames;

        for (const auto& entry : std::filesystem::directory_iterator(dirPath)) {
            if (entry.is_regular_file()) {
                std::string extension = entry.path().extension().string();
                if (extensions.find(extension) != extensions.end()) {
                    fileNames.push_back(entry.path().filename().string());
                }
            }   
        }

        return fileNames;
    }
};