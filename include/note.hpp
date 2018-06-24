//
// Created by Giorgio Antonioli on 24/06/18.
//

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

    std::string getTitle();

    std::string getDescription();
};

std::string Note::getTitle() {
    return title;
}

std::string Note::getDescription() {
    return description;
}