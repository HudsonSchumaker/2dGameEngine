/*
	SchumakerTeam
	Hudson Schumaker
*/

#include "../include/Common.h"

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

    static std::vector<std::string> listImageFilesInDirectory(const std::filesystem::path& dirPath) {
        std::vector<std::string> imageFileNames;
        const std::set<std::string> imageExtensions = {".jpg", ".jpeg", ".png", ".bmp", ".gif"};

        for (const auto& entry : std::filesystem::directory_iterator(dirPath)) {
            if (entry.is_regular_file()) {
                std::string extension = entry.path().extension().string();
                if (imageExtensions.find(extension) != imageExtensions.end()) {
                    imageFileNames.push_back(entry.path().filename().string());
                }
            }   
        }

        return imageFileNames;
    }
};