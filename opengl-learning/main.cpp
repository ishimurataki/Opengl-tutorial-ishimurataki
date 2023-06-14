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

int main(int argc, const char * argv[]) {
    
    if (argc < 2) {
        return opening_a_window();
    }
    
    if (strcmp(argv[1], "1") == 0) {
        return opening_a_window();
    } else if (strcmp(argv[1], "2") == 0) {
        return the_first_triangle();
    } else if (strcmp(argv[1], "3") == 0) {
        return matrices();
    } else {
        fprintf(stderr, "Invalid tutorial number option.\n");
    }
    return -1;
    
}
