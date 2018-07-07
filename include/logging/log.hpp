//
// Created by Giorgio Antonioli on 26/06/18.
//

#ifndef NOTES_LOG_HPP
#define NOTES_LOG_HPP

#include <string>

#include "logger.hpp"

class Log {
private:
    static Logger *logger;

public:
    static void registerLogger(Logger &logger);

    static void log(Severity severity, const std::string &msg);
};

#endif //NOTES_LOG_HPP
