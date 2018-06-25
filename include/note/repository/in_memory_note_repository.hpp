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
    void insert(const Note &note) override;

    void remove(const Note &note) override;

    std::vector<Note> getAll() override;
};

#endif //NOTES_IN_MEMORY_NOTE_REPOSITORY_HPP
