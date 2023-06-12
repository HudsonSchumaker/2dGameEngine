/*
	SchumakerTeam
	Dodoi Engine
	Hudson Schumaker
*/

#pragma once
#include "../include/Common.h"

class FileUtils {
public:
    static std::string getClearName(std::filesystem::path file);
    static std::string getClearName(const std::string path);
    static std::string getName(const std::string path); 
    static std::string getClearPath(const std::string path);
    static std::string getFileExtension(std::filesystem::path file);
    static std::string getFileExtension(const std::string fileName);
    static std::vector<std::string> listImageFilesInFolder();
    static std::vector<std::string> listAudioFilesInFolder();
    static std::vector<std::string> listFilesInFolder(const std::filesystem::path dirPath, const std::set<std::string>& extensions);
};
