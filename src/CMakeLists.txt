set(SOURCES
        main.cpp
        note/note.cpp note/repository/in_memory_note_repository.cpp)

add_executable(${EXE_NAME} ${SOURCES})