//
// Created by Giorgio Antonioli on 28/06/18.
//

#include "note_presenter.hpp"
#include "note_view.hpp"

NotePresenterImpl::NotePresenterImpl(NoteRepository * repository) {
    this->repository = repository;
}

void NotePresenterImpl::attachView(NoteView *view) {
    this->view = view;

    auto note = std::make_unique<Note>("dummy", "example");
    requestNoteSaving(*note);
    requestNoteSaving(*note);
    requestAllNotes();
    requestNoteDeletion(*note);
    requestAllNotes();
}

void NotePresenterImpl::requestAllNotes() {
    auto notes = repository->getAll();
    if (notes.empty()) {
        view->showZeroNotes();
    } else {
        view->showAllNotes(notes);
    }
}

void NotePresenterImpl::requestNoteSaving(const Note &note) {
    repository->insert(note);
    view->showSuccessfulSaving();
}

void NotePresenterImpl::requestNoteDeletion(const Note &note) {
    repository->remove(note);
    view->showSuccessfulDeletion();
}
