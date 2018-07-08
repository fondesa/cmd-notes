//
// Created by Giorgio Antonioli on 28/06/18.
//

#include "command.hpp"
#include "note_presenter.hpp"
#include "note_view.hpp"

NotePresenterImpl::NotePresenterImpl(NoteRepository &repository,
                                     CommandContainer &commandContainer) : repository(repository),
                                                                           commandContainer(commandContainer) {

    auto wrapIO = [&](std::function<void()> execution) -> std::function<void()> {
        return [=]() mutable {
            view->prepareOutputView();
            execution();
            view->discardPreviousInputView();
            view->allowUserInput();
        };
    };

    helpCommand = std::make_unique<Command>("help", "h", wrapIO([&]() {
        //TODO
    }));
    commandContainer.insertCommand(*helpCommand);

    auto insertCommand = [&](std::string name, std::string shortName, std::function<void()> execution) {
        auto command = std::make_unique<Command>(name, shortName, execution);
        commandContainer.insertCommand(*command);
    };

    insertCommand("list", "ls", wrapIO([&]() {
        requestAllNotes();
    }));
    insertCommand("quit", "q", [&](){
        // The user exit.
    });
}

void NotePresenterImpl::attachView(NoteView &view) {
    this->view = &view;

    auto note = std::make_unique<Note>("dummy", "example");
    requestNoteSaving(*note);
    requestNoteSaving(*note);

    view.allowUserInput();
}

void NotePresenterImpl::inputReceived(std::string input) {
    auto command = commandContainer.provideCommandByName(input);
    if (command) {
        command->execute();
    } else {
        view->prepareOutputView();
        view->showUnrecognizedCommandView(input, *helpCommand);
        view->discardPreviousInputView();
        view->allowUserInput();
    }
}

void NotePresenterImpl::requestAllNotes() {
    auto notes = repository.getAll();
    if (notes.empty()) {
        view->showZeroNotes();
    } else {
        view->showAllNotes(notes);
    }
}

void NotePresenterImpl::requestNoteSaving(const Note &note) {
    repository.insert(note);
    view->showSuccessfulSaving();
}

void NotePresenterImpl::requestNoteDeletion(const Note &note) {
    repository.remove(note);
    view->showSuccessfulDeletion();
}
