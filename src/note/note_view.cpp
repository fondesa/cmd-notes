//
// Created by Giorgio Antonioli on 28/06/18.
//

#include <iostream>
#include <vector>
#include <iomanip>

#include "note.hpp"
#include "note_view.hpp"
#include "print_util.hpp"

void ConsoleNoteView::injectPresenter(NotePresenter &presenter) {
    this->presenter = &presenter;
    presenter.attachView(*this);
}

void ConsoleNoteView::showCommandInputView() {
    std::string line;
    std::cout << "Insert command: ";
    std::getline(std::cin, line);
    presenter->commandInputReceived(line);
}

void ConsoleNoteView::showNoteTitleInputView() {
    std::string line;
    std::cout << "Write the note's title: ";
    std::getline(std::cin, line);
    presenter->noteTitleInputReceived(line);
}

void ConsoleNoteView::showNoteDescriptionInputView() {
    std::string line;
    std::cout << "Write the note's description: ";
    std::getline(std::cin, line);
    presenter->noteDescriptionInputReceived(line);
}

void ConsoleNoteView::discardPreviousInputView() {
    print_util::printDivider();
}

void ConsoleNoteView::prepareNewView() {
    std::cout << std::endl;
}

void ConsoleNoteView::showHelpView(std::vector<Command> commands) {
    std::cout << "The following commands are available:" << std::endl << std::endl;
    for (auto const &command : commands) {
        auto leftColumn = "- \"" + command.getName() + "\", \"" + command.getShortName() + "\"";
        std::cout << std::setw(20)
                  << std::left
                  << leftColumn
                  << command.getDescription()
                  << std::endl;
    }
}

void ConsoleNoteView::showUnrecognizedCommandView(const std::string &receivedInput, const Command &helpCommand) {
    std::cout << "The command \""
              << receivedInput
              << "\" can't be recognized."
              << "\nUse \""
              << helpCommand.getName()
              << "\" or \""
              << helpCommand.getShortName()
              << "\" to show the available commands."
              << std::endl;
}

void ConsoleNoteView::showZeroNotes() {
    std::cout << "There aren't notes." << std::endl;
}

void ConsoleNoteView::showAllNotes(std::vector<Note> notes) {
    std::cout << "There are the following notes:\n" << std::endl;
    for (auto it = notes.begin(); it != notes.end(); ++it) {
        auto note = *it;
        std::cout << "-\tTitle: "
                  << note.getTitle()
                  << std::endl
                  << "\tDescription: "
                  << note.getDescription()
                  << std::endl;
        if (it != notes.end() - 1) {
            std::cout << std::endl;
        }
    }
}

void ConsoleNoteView::showInvalidNoteTitleView() {
    std::cout << "This note's title is not valid." << std::endl;
}

void ConsoleNoteView::showNoteAlreadyExistView() {
    std::cout << "A note with the same title and description already exists." << std::endl;
}

void ConsoleNoteView::showNoteSuccessfulSaving() {
    std::cout << "The note was successfully saved." << std::endl;
}

void ConsoleNoteView::showNoteSuccessfulDeletion() {
    std::cout << "The note was successfully deleted." << std::endl;
}
