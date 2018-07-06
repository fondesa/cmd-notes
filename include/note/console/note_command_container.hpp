//
// Created by Giorgio Antonioli on 06/07/18.
//

#ifndef NOTES_NOTE_COMMAND_PROVIDER_HPP
#define NOTES_NOTE_COMMAND_PROVIDER_HPP

#include <vector>
#include <map>
#include "command_container.hpp"

class NoteCommandContainer : public CommandContainer {
private:
    std::vector<Command> commands;
public:
    void insertCommand(const Command &command) override;

    std::vector<Command> provideCommandList() override;

    Command *provideCommandByName(std::string name) override;
};

#endif //NOTES_NOTE_COMMAND_PROVIDER_HPP
