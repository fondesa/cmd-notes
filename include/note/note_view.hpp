//
// Created by Giorgio Antonioli on 28/06/18.
//

#ifndef NOTES_NOTE_VIEW_HPP
#define NOTES_NOTE_VIEW_HPP

#include <vector>

#include "note.hpp"
#include "note_presenter.hpp"

class NotePresenter;

class NoteView {
public:
    virtual void injectPresenter(NotePresenter &presenter)=0;

    virtual void allowUserInput()=0;

    virtual void discardPreviousInputView()=0;

    virtual void prepareOutputView()=0;

    virtual void showUnrecognizedCommandView(const std::string &receivedInput, const Command &helpCommand)=0;

    virtual void showZeroNotes()=0;

    virtual void showAllNotes(std::vector<Note> notes)=0;

    virtual void showSuccessfulSaving()=0;

    virtual void showSuccessfulDeletion()=0;
};

class ConsoleNoteView : public NoteView {
private:
    NotePresenter *presenter = nullptr;

public:
    void injectPresenter(NotePresenter &presenter) override;

    void allowUserInput() override;

    void discardPreviousInputView() override;

    void prepareOutputView() override;

    void showUnrecognizedCommandView(const std::string &receivedInput, const Command &helpCommand) override;

    void showZeroNotes() override;

    void showAllNotes(std::vector<Note> notes) override;

    void showSuccessfulSaving() override;

    void showSuccessfulDeletion() override;
};

#endif //NOTES_NOTE_VIEW_HPP
