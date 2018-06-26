//
// Created by Giorgio Antonioli on 26/06/18.
//

#include "log.hpp"
#include "logger.hpp"

Logger* Log::logger = nullptr;

void Log::registerLogger(Logger *logger) {
    Log::logger = logger;
}

void Log::log(Severity severity, const std::string &msg) {
    if (logger) {
        logger->log(severity, msg);
    }
}