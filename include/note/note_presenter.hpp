//
// Created by Giorgio Antonioli on 28/06/18.
//

#ifndef NOTES_NOTE_PRESENTER_HPP
#define NOTES_NOTE_PRESENTER_HPP

#include "note_repository.hpp"
#include "note_view.hpp"

class NoteView;

class NotePresenter {
public:
    virtual void attachView(NoteView *view)=0;

    virtual void requestAllNotes()=0;

    virtual void requestNoteSaving(const Note &note)=0;

    virtual void requestNoteDeletion(const Note &note)=0;
};

class NotePresenterImpl : public NotePresenter {
private:
    NoteView *view;
    NoteRepository *repository;

public:
    explicit NotePresenterImpl(NoteRepository *repository);

    void attachView(NoteView *view) override;

    void requestAllNotes() override;

    void requestNoteSaving(const Note &note) override;

    void requestNoteDeletion(const Note &note) override;
};

#endif //NOTES_NOTE_PRESENTER_HPP
