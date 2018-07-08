//
// Created by Giorgio Antonioli on 28/06/18.
//

#include <iostream>
#include <vector>

#include "note.hpp"
#include "note_view.hpp"
#include "print_util.hpp"

void ConsoleNoteView::injectPresenter(NotePresenter &presenter) {
    this->presenter = &presenter;
    presenter.attachView(*this);
}

void ConsoleNoteView::allowUserInput() {
    std::string line;
    std::cout << "Insert command: ";
    std::getline(std::cin, line);
    presenter->inputReceived(line);
}

void ConsoleNoteView::discardPreviousInputView() {
    print_util::printDivider();
}

void ConsoleNoteView::prepareOutputView() {
    std::cout << std::endl;
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
                  << "\n \tDescription: "
                  << note.getDescription();
        if (it != notes.end() - 1) {
            std::cout << "\n";
        }
        std::cout << std::endl;
    }
}

void ConsoleNoteView::showSuccessfulSaving() {
    std::cout << "The note was successfully saved." << std::endl;
}

void ConsoleNoteView::showSuccessfulDeletion() {
    std::cout << "The note was successfully deleted." << std::endl;
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
