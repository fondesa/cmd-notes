//
// Created by Giorgio Antonioli on 24/06/18.
//

#include <iostream>
#include <memory>

#include "note.hpp"
#include "log.hpp"
#include "logger.hpp"
#include "print_util.hpp"
#include "in_memory_note_repository.hpp"

void printNotes(NoteRepository *repository);

int main() {
    auto logger = std::make_unique<SysLogger>();
    // Register the logger used for this application.
    Log::registerLogger(logger.get());

    auto note = std::make_unique<Note>("dummy", "example");

    auto repository = std::make_unique<InMemoryNoteRepository>();
    repository->insert(*note);
    repository->insert(*note);

    printNotes(repository.get());
    repository->remove(*note);
    printNotes(repository.get());
    return 0;
}

void printNotes(NoteRepository *repository) {
    print_util::printDivider();
    auto notes = repository->getAll();
    if (notes.empty()) {
        std::cout << "The repository is empty" << std::endl;
        return;
    }

    auto size = notes.size();
    std::string notesWord;
    if (size == 1) {
        notesWord = "note";
    } else {
        notesWord = "notes";
    }
    std::cout << "The repository contains " << size << " " << notesWord << ":" << std::endl;
    for (auto &note : notes) {
        std::cout << note.toString() << std::endl;
    }
    print_util::printDivider();
}