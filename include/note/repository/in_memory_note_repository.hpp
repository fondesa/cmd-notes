//
// Created by Giorgio Antonioli on 24/06/18.
//

#ifndef NOTES_IN_MEMORY_NOTE_REPOSITORY_HPP
#define NOTES_IN_MEMORY_NOTE_REPOSITORY_HPP

#include <iostream>
#include <vector>
#include <algorithm>
#include "note_repository.hpp"

class InMemoryNoteRepository : public NoteRepository {
private:
    std::vector<Note> notes;

public:
    void insert(const Note &note) override {
        auto position = std::find(notes.begin(), notes.end(), note);
        if (position != notes.end()) {
            // An equal element was found.
            std::cout << "The element " << note.toString() << " already existed in the repo." << std::endl;
            return;
        }
        std::cout << "The element " << note.toString() << " was added to the repo." << std::endl;
        notes.push_back(note);
    }

    void remove(const Note &note) override {
        std::cout << "The element " << note.toString() << " was removed from the repo." << std::endl;
        notes.erase(std::remove(notes.begin(), notes.end(), note), notes.end());
    }

    std::vector<Note> getAll() override {
        return notes;
    }
};

#endif //NOTES_IN_MEMORY_NOTE_REPOSITORY_HPP
