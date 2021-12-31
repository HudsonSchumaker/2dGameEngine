#include <iostream>
#include <string>
#include <chrono>
#include <ctime>
#include "Logger.hpp"

std::vector<LogEntry> Logger::messages;

void Logger::Info(const std::string& message) {
    LogEntry logEntry;
    logEntry.type = LOG_INFO;
    logEntry.message = "LOG: [" + CurrentDateTimeToString() + "]: " + message;
    
    std::cout << "\x1B[32m" << logEntry.message << "\033[0m" << std::endl;
    messages.push_back(logEntry);
}

void Logger::Warning(const std::string& message) {
    LogEntry logEntry;
    logEntry.type = LOG_WARNING;
    logEntry.message = "LOG: [" + CurrentDateTimeToString() + "]: " + message;
    
    std::cout << "\x1B[33m" << logEntry.message << "\033[0m" << std::endl;
    messages.push_back(logEntry);
}

void Logger::Error(const std::string& message) {
    LogEntry logEntry;
    logEntry.type = LOG_ERROR;
    logEntry.message = "LOG: [" + CurrentDateTimeToString() + "]: " + message;
    
    std::cout << "\x1B[31m" << logEntry.message << "\033[0m" << std::endl;
    messages.push_back(logEntry);
}

void Logger::Engine(const std::string& message) {
    LogEntry logEntry;
    logEntry.type = LOG_ENGINE;
    logEntry.message = "LOG: [" + CurrentDateTimeToString() + "]: " + message;
    
    std::cout << "\x1B[34m" << logEntry.message << "\033[0m" << std::endl;
    messages.push_back(logEntry);
}

std::string Logger::CurrentDateTimeToString() {
    std::time_t now = std::chrono::system_clock::to_time_t(std::chrono::system_clock::now());
    std::string output(30, '\0');
    std::strftime(&output[0], output.size(), "%d-%b-%Y %H:%M:%S", std::localtime(&now));
    return output;
}