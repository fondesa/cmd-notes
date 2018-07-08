//
// Created by Giorgio Antonioli on 25/06/18.
//

#ifndef NOTES_PRINT_UTIL_HPP
#define NOTES_PRINT_UTIL_HPP

#include <iostream>
#include <iomanip>

namespace print_util {
    void printDivider();

    void printDivider() {
        std::cout << std::endl << std::setfill('=') << std::setw(70) << "=" << std::endl << std::endl;
        // Resets the filling using the space character.
        std::cout << std::setfill(' ');
    }
}

#endif //NOTES_PRINT_UTIL_HPP
