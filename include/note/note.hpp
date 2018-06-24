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
    Note(std::string title, std::string description) {
        this->title = std::move(title);
        this->description = std::move(description);
    }

    std::string getTitle() const;

    std::string getDescription() const;

    std::string toString() const;

    bool operator==(const Note &n) const;
};

std::string Note::getTitle() const {
    return title;
}

std::string Note::getDescription() const {
    return description;
}

std::string Note::toString() const {
    return "Note { title: " + title + ", description: " + description + " }";
}

bool Note::operator==(const Note &n) const {
    if (this == &n) {
        return true;
    }
    return this->title == n.title &&
            this->description == n.description;
}

#endif //NOTES_NOTE_HPP
