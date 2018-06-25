//
// Created by Giorgio Antonioli on 25/06/18.
//

#include "note.hpp"
#include "in_memory_note_repository.hpp"

void InMemoryNoteRepository::insert(const Note &note) {
    auto position = std::find(notes.begin(), notes.end(), note);
    if (position != notes.end()) {
        // An equal element was found.
        std::cout << "The element " << note.toString() << " already existed in the repo." << std::endl;
        return;
    }
    std::cout << "The element " << note.toString() << " was added to the repo." << std::endl;
    notes.push_back(note);
}

void InMemoryNoteRepository::remove(const Note &note) {
    std::cout << "The element " << note.toString() << " was removed from the repo." << std::endl;
    notes.erase(std::remove(notes.begin(), notes.end(), note), notes.end());
}

std::vector<Note> InMemoryNoteRepository::getAll() {
    return notes;
}