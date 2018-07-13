//
// Created by Giorgio Antonioli on 25/06/18.
//

#include "note.hpp"
#include "log.hpp"
#include "in_memory_note_repository.hpp"

bool InMemoryNoteRepository::contains(const Note &note) {
    auto position = std::find(notes.begin(), notes.end(), note);
    // An equal element was found.
    return position != notes.end();
}

void InMemoryNoteRepository::insert(const Note &note) {
    Log::log(DEBUG, "The element "+ note.toString() +  " was added to the repo");
    notes.push_back(note);
}

void InMemoryNoteRepository::remove(const Note &note) {
    Log::log(DEBUG, "The element "+ note.toString() +  " was removed from the repo");
    notes.erase(std::remove(notes.begin(), notes.end(), note), notes.end());
}

std::vector<Note> InMemoryNoteRepository::getAll() {
    return notes;
}