#pragma once
#include <string>
#include <vector>

enum LogType {
    LOG_ERROR,
    LOG_WARNING,
    LOG_INFO,
    LOG_ENGINE
};

struct LogEntry {
    int type;
    std::string message;
};

class Logger final {
    private:
        static std::string CurrentDateTimeToString();

    public:
        static std::vector<LogEntry> messages;  
        static void Info(const std::string& message);
        static void Warning(const std::string& message);
        static void Error(const std::string& message);
        static void Engine(const std::string& message);
};