//
// Created by Giorgio Antonioli on 24/06/18.
//

#include <iostream>
#include <memory>

#include "note.hpp"
#include "log.hpp"
#include "logger.hpp"
#include "note_view.hpp"
#include "note_presenter.hpp"
#include "in_memory_note_repository.hpp"
#include "note_command_container.hpp"

int main() {
    std::unique_ptr<Logger> logger = std::make_unique<SysLogger>();
    // Register the logger used for this application.
    Log::registerLogger(*logger);

    std::unique_ptr<NoteRepository> repository = std::make_unique<InMemoryNoteRepository>();
    std::unique_ptr<CommandContainer> commandContainer = std::make_unique<NoteCommandContainer>();
    std::unique_ptr<NoteView> noteView = std::make_unique<ConsoleNoteView>();
    std::unique_ptr<NotePresenter> notePresenter = std::make_unique<NotePresenterImpl>(*repository, *commandContainer);
    noteView->injectPresenter(*notePresenter);
    return 0;
}