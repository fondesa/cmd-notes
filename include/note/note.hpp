//
// Created by Giorgio Antonioli on 24/06/18.
//

#ifndef NOTES_NOTE_HPP
#define NOTES_NOTE_HPP

#include <string>
#include <utility>

class Note {
private:
    std::string title;
    std::string description;

public:
    Note(std::string title, std::string description);

    std::string getTitle() const;

    std::string getDescription() const;

    std::string toString() const;

    bool operator==(const Note &n) const;
};

#endif //NOTES_NOTE_HPP
