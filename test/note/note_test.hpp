//
// Created by Giorgio Antonioli on 02/07/18.
//

#ifndef NOTES_NOTE_TEST_HPP
#define NOTES_NOTE_TEST_HPP

#include "gtest/gtest.h"

// The fixture for testing class Foo.
class NoteTest : public ::testing::Test {
protected:
    NoteTest();

    virtual ~NoteTest();

    virtual void SetUp();

    virtual void TearDown();
};

#endif //NOTES_NOTE_TEST_HPP
