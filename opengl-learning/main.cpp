//
//  main.cpp
//  opengl-learning
//
//  Created by Takanao Ishimura on 6/10/23.
//

#include <iostream>
#include "1-opening-a-window.hpp"
#include "2-the-first-triangle.hpp"
#include "3-matrices.hpp"
#include "4-a-colored-cube.hpp"
#include "5-a-textured-cube.hpp"
#include "6-keyboard-and-mouse.hpp"

int main(int argc, const char * argv[]) {
    
    if (argc < 2) {
        return opening_a_window();
    }
    
    if (strcmp(argv[1], "1") == 0) {
        printf("Running exercise 1 - opening a window.\n");
        return opening_a_window();
    } else if (strcmp(argv[1], "2") == 0) {
        printf("Running exercise 2 - the first triangle.\n");
        return the_first_triangle();
    } else if (strcmp(argv[1], "3") == 0) {
        printf("Running exercise 3 - matrices.\n");
        return matrices();
    } else if (strcmp(argv[1], "4") == 0) {
        printf("Running exercise 4 - a colored cube.\n");
        return a_colored_cube();
    } else if (strcmp(argv[1], "5") == 0) {
        printf("Running exercise 5 - a textured cube.\n");
        return a_textured_cube();
    } else if (strcmp(argv[1], "6") == 0) {
        printf("Running exercise 6 - keyboard and mouse.\n");
        return keyboard_and_mouse();
    } else {
        fprintf(stderr, "Invalid tutorial number option.\n");
    }
    return -1;
    
}
