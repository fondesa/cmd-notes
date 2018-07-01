//
// Created by Giorgio Antonioli on 01/07/18.
//

#include "command.hpp"
#include <utility>

Command::Command(std::string name, std::string shortName, std::function<void()> execution) {
    this->name = std::move(name);
    this->shortName = std::move(shortName);
    this->execution = std::move(execution);
}

std::string Command::getName() {
    return name;
}

std::string Command::getShortName() {
    return shortName;
}

void Command::execute() {
    execution();
}
