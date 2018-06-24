#include <iostream>
#include "note.hpp"

int main() {
    auto note = new Note { "dummy","exadg"};
    std::cout << "title: " << note->getTitle();
    return 0;
}