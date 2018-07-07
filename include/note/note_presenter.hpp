//
// Created by Giorgio Antonioli on 28/06/18.
//

#ifndef NOTES_NOTE_PRESENTER_HPP
#define NOTES_NOTE_PRESENTER_HPP

#include "command_container.hpp"
#include "note_repository.hpp"
#include "note_view.hpp"

class NoteView;

class NotePresenter {
public:
    virtual void attachView(NoteView *view)=0;

    virtual void inputReceived(std::string input)=0;

    virtual void requestAllNotes()=0;

    virtual void requestNoteSaving(const Note &note)=0;

    virtual void requestNoteDeletion(const Note &note)=0;
};

class NotePresenterImpl : public NotePresenter {
private:
    NoteRepository &repository;
    CommandContainer &commandContainer;
    NoteView *view;
    std::unique_ptr<Command> helpCommand;

public:
    explicit NotePresenterImpl(NoteRepository &repository,
                               CommandContainer &commandContainer);

    void attachView(NoteView *view) override;

    void inputReceived(std::string input) override;

    void requestAllNotes() override;

    void requestNoteSaving(const Note &note) override;

    void requestNoteDeletion(const Note &note) override;
};

#endif //NOTES_NOTE_PRESENTER_HPP
