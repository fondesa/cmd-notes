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
    virtual void injectPresenter(NotePresenter * presenter)=0;

    virtual void showZeroNotes()=0;

    virtual void showAllNotes(std::vector<Note> notes)=0;

    virtual void showSuccessfulSaving()=0;

    virtual void showSuccessfulDeletion()=0;
};

class ConsoleNoteView : public NoteView {
private:
    NotePresenter *presenter = nullptr;

public:
    void injectPresenter(NotePresenter *presenter) override;

    void showZeroNotes() override;

    void showAllNotes(std::vector<Note> notes) override;

    void showSuccessfulSaving() override;

    void showSuccessfulDeletion() override;
};

#endif //NOTES_NOTE_VIEW_HPP
