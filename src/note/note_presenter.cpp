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
            view->prepareNewView();
            execution();
            view->discardPreviousInputView();
            view->showCommandInputView();
        };
    };

    helpCommand = std::make_unique<Command>("help", "h", "Shows the list of the available commands.", wrapIO([&]() {
        auto commands = commandContainer.provideCommandList();
        // Sorts the vector using the "<" operator.
        std::sort(commands.begin(), commands.end());
        view->showHelpView(commands);
    }));
    commandContainer.insertCommand(*helpCommand);

    auto insertCommand = [&](std::string name,
                             std::string shortName,
                             std::string description,
                             std::function<void()> execution) {
        auto command = std::make_unique<Command>(name, shortName, description, execution);
        commandContainer.insertCommand(*command);
    };

    insertCommand("list", "ls", "Lists all the saved notes.", wrapIO([&]() {
        auto notes = repository.getAll();
        if (notes.empty()) {
            view->showZeroNotes();
        } else {
            view->showAllNotes(notes);
        }
    }));

    insertCommand("quit", "q", "Quits the program.", [&]() {
        // The user exited.
    });

    insertCommand("insert", "in", "Inserts a new note.", wrapIO([&]() {
        view->showNoteTitleInputView();
    }));
}

void NotePresenterImpl::attachView(NoteView &view) {
    this->view = &view;

    view.showCommandInputView();
}

void NotePresenterImpl::commandInputReceived(std::string input) {
    auto command = commandContainer.provideCommandByName(input);
    if (command) {
        command->execute();
    } else {
        view->prepareNewView();
        view->showUnrecognizedCommandView(input, *helpCommand);
        view->discardPreviousInputView();
        view->showCommandInputView();
    }
}

void NotePresenterImpl::noteTitleInputReceived(std::string input) {
    view->prepareNewView();
    if (input.empty()) {
        view->showInvalidNoteTitleView();
        view->prepareNewView();
        view->showNoteTitleInputView();
    } else {
        pendingTitle = input;
        view->showNoteDescriptionInputView();
    }
}

void NotePresenterImpl::noteDescriptionInputReceived(std::string input) {
    view->prepareNewView();

    auto note = std::make_unique<Note>(pendingTitle, input);
    if (repository.contains(*note)) {
        view->showNoteAlreadyExistView();
    } else {
        repository.insert(*note);
        view->showNoteSuccessfulSaving();
    }
    view->discardPreviousInputView();
    view->showCommandInputView();
}

void NotePresenterImpl::requestNoteDeletion(const Note &note) {
    repository.remove(note);
    view->showNoteSuccessfulDeletion();
}