//
// Created by Giorgio Antonioli on 06/07/18.
//

#include "command.hpp"
#include "note_command_container.hpp"

void NoteCommandContainer::insertCommand(const Command &command) {
    commands.push_back(command);
}

std::vector<Command> NoteCommandContainer::provideCommandList() {
    return commands;
}

Command *NoteCommandContainer::provideCommandByName(std::string name) {
    for (auto &command : commands) {
        if (command.getName() == name || command.getShortName() == name) {
            return &command;
        }
    }
    return nullptr;
}
