//
// Created by Giorgio Antonioli on 25/06/18.
//

#include "note.hpp"

Note::Note(std::string title, std::string description) {
    this->title = std::move(title);
    this->description = std::move(description);
}

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