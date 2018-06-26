//
// Created by Giorgio Antonioli on 26/06/18.
//

#include <iostream>

#include "logger.hpp"

void SysLogger::log(Severity severity, const std::string &msg) {
    std::string tag;
    switch (severity) {
        case DEBUG:
            tag = "DEBUG";
            break;
        case WARNING:
            tag = "WARNING";
            break;
        case ERROR:
            tag = "ERROR";
            break;
        default:
            return;
    }

    std::cout << "[" << tag << "] " << msg << std::endl;
}
