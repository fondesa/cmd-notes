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

    virtual void showCommandInputView()=0;

    virtual void showNoteTitleInputView()=0;

    virtual void showNoteDescriptionInputView()=0;

    virtual void discardPreviousInputView()=0;

    virtual void prepareNewView()=0;

    virtual void showUnrecognizedCommandView(const std::string &receivedInput, const Command &helpCommand)=0;

    virtual void showHelpView(std::vector<Command> commands)=0;

    virtual void showZeroNotes()=0;

    virtual void showAllNotes(std::vector<Note> notes)=0;

    virtual void showInvalidNoteTitleView()=0;

    virtual void showNoteSuccessfulSaving()=0;

    virtual void showNoteAlreadyExistView()=0;

    virtual void showNoteSuccessfulDeletion()=0;
};

class ConsoleNoteView : public NoteView {
private:
    NotePresenter *presenter = nullptr;

public:
    void injectPresenter(NotePresenter &presenter) override;

    void showCommandInputView() override;

    void showNoteTitleInputView() override;

    void showNoteDescriptionInputView() override;

    void discardPreviousInputView() override;

    void prepareNewView() override;

    void showUnrecognizedCommandView(const std::string &receivedInput, const Command &helpCommand) override;

    void showHelpView(std::vector<Command> commands) override;

    void showZeroNotes() override;

    void showAllNotes(std::vector<Note> notes) override;

    void showInvalidNoteTitleView() override;

    void showNoteSuccessfulSaving() override;

    void showNoteAlreadyExistView() override;

    void showNoteSuccessfulDeletion() override;
};

#endif //NOTES_NOTE_VIEW_HPP
