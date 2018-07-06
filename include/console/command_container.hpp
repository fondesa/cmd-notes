//
// Created by Giorgio Antonioli on 06/07/18.
//

#ifndef NOTES_COMMAND_PROVIDER_HPP
#define NOTES_COMMAND_PROVIDER_HPP

#include "command.hpp"

class CommandContainer {
public:
    virtual void insertCommand(const Command &command)=0;

    virtual std::vector<Command> provideCommandList()=0;

    virtual Command *provideCommandByName(std::string name)=0;
};

#endif //NOTES_COMMAND_PROVIDER_HPP
