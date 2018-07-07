//
// Created by Giorgio Antonioli on 28/06/18.
//

#include "command.hpp"
#include "note_presenter.hpp"
#include "note_view.hpp"

NotePresenterImpl::NotePresenterImpl(NoteRepository *repository,
                                     CommandContainer *commandContainer) {
    this->repository = repository;
    this->commandContainer = commandContainer;
    helpCommand = std::make_unique<Command>("help", "h", [&]() {
        //TODO
    });
    commandContainer->insertCommand(*helpCommand);

    auto insertCommand = [&](std::string name, std::string shortName, std::function<void()> execution) {
        auto command = std::make_unique<Command>(name, shortName, execution);
        commandContainer->insertCommand(*command);
    };
    insertCommand("list", "ls", [&]() {
        requestAllNotes();
    });
}

void NotePresenterImpl::attachView(NoteView *view) {
    this->view = view;

    auto note = std::make_unique<Note>("dummy", "example");
    requestNoteSaving(*note);
    requestNoteSaving(*note);

    view->allowUserInput();
}

void NotePresenterImpl::inputReceived(std::string input) {
    auto command = commandContainer->provideCommandByName(input);
    if (command) {
        command->execute();
    } else {
        view->showUnrecognizedCommandView(input, *helpCommand);
    }
}

void NotePresenterImpl::requestAllNotes() {
    auto notes = repository->getAll();
    if (notes.empty()) {
        view->showZeroNotes();
    } else {
        view->showAllNotes(notes);
    }
}

void NotePresenterImpl::requestNoteSaving(const Note &note) {
    repository->insert(note);
    view->showSuccessfulSaving();
}

void NotePresenterImpl::requestNoteDeletion(const Note &note) {
    repository->remove(note);
    view->showSuccessfulDeletion();
}
