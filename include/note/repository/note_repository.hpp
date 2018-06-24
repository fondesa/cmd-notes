//
// Created by Giorgio Antonioli on 24/06/18.
//

#ifndef NOTES_NOTE_REPOSITORY_HPP
#define NOTES_NOTE_REPOSITORY_HPP

#include "note.hpp"

class NoteRepository {
public:
    virtual void insert(const Note &note)=0;

    virtual void remove(const Note &note)=0;

    virtual std::vector<Note> getAll()=0;
};

#endif //NOTES_NOTE_REPOSITORY_HPP
