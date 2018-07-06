//
// Created by Giorgio Antonioli on 30/06/18.
//

#ifndef NOTES_COMMAND_HPP
#define NOTES_COMMAND_HPP

#include <string>
#include <functional>

class Command {
private:
    std::string name;
    std::string shortName;
    std::function<void()> execution;
public:
    Command(std::string name, std::string shortName, std::function<void()> execution);

    std::string getName() const ;

    std::string getShortName() const ;

    void execute();
};

#endif //NOTES_COMMAND_HPP
