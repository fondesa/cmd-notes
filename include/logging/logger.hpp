//
// Created by Giorgio Antonioli on 26/06/18.
//

#ifndef NOTES_LOGGER_HPP
#define NOTES_LOGGER_HPP

#include <string>

enum Severity {
    DEBUG, WARNING, ERROR
};

class Logger {
public:
    virtual void log(Severity severity, const std::string &msg)=0;
};

class SysLogger : public Logger {
public:
    void log(Severity severity, const std::string &msg) override;
};

#endif //NOTES_LOGGER_HPP
