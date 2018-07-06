set(SOURCES
        main.cpp
        console/command.cpp
        logging/log.cpp
        logging/logger.cpp
        note/note.cpp
        note/note_presenter.cpp
        note/note_view.cpp
        note/console/note_command_container.cpp
        note/repository/in_memory_note_repository.cpp)

add_executable(${EXE_NAME} ${SOURCES})