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
    virtual void attachView(NoteView &view)=0;

    virtual void commandInputReceived(std::string input)=0;

    virtual void noteTitleInputReceived(std::string input)=0;

    virtual void noteDescriptionInputReceived(std::string input)=0;

    virtual void requestNoteDeletion(const Note &note)=0;
};

class NotePresenterImpl : public NotePresenter {
private:
    NoteRepository &repository;
    CommandContainer &commandContainer;
    NoteView *view;
    std::unique_ptr<Command> helpCommand;
    std::string pendingTitle;

public:
    explicit NotePresenterImpl(NoteRepository &repository,
                               CommandContainer &commandContainer);

    void attachView(NoteView &view) override;

    void commandInputReceived(std::string input) override;

    void noteTitleInputReceived(std::string input) override;

    void noteDescriptionInputReceived(std::string input) override;

    void requestNoteDeletion(const Note &note) override;
};

#endif //NOTES_NOTE_PRESENTER_HPP
