//
// Created by Giorgio Antonioli on 01/07/18.
//

#include "command.hpp"
#include <utility>

Command::Command(std::string name, std::string shortName, std::string description, std::function<void()> execution) {
    this->name = std::move(name);
    this->description = std::move(description);
    this->shortName = std::move(shortName);
    this->execution = std::move(execution);
}

std::string Command::getName() const {
    return name;
}

std::string Command::getShortName() const {
    return shortName;
}

std::string Command::getDescription() const {
    return description;
}

void Command::execute() {
    execution();
}

bool Command::operator<(const Command &command) const {
    return name < command.name;
}
