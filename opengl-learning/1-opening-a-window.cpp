//
//  1-opening-a-window.cpp
//  opengl-learning
//
//  Created by Takanao Ishimura on 6/11/23.
//

#include "1-opening-a-window.hpp"

int opening_a_window() {
    // Initialise GLFW
    if( !glfwInit() )
    {
        fprintf( stderr, "Failed to initialize GLFW\n" );
        return -1;
    }
    
    glfwWindowHint(GLFW_SAMPLES, 4); // 4x antialiasing
    glfwWindowHint(GLFW_VERSION_MAJOR, 2); // We want OpenGL 2.1
    glfwWindowHint(GLFW_VERSION_MINOR, 1);
    
    // Open a window and create its OpenGL context
    GLFWwindow* window;
    window = glfwCreateWindow(1024, 768, "Tutorial 01", NULL, NULL);
    if (window == NULL) {
        fprintf(stderr, "Failed to open GLFW window.\n");
        glfwTerminate();
        return -1;
    }
    glfwMakeContextCurrent(window); // Initialize GLEW
    if (glewInit() != GLEW_OK) {
        fprintf(stderr, "Failed to initialize GLEW\n");
        glfwTerminate();
        return -1;
    }
    
    // Ensure we can capture the escape key being pressed below
    glfwSetInputMode(window, GLFW_STICKY_KEYS, GL_TRUE);
    
    while (glfwGetKey(window, GLFW_KEY_ESCAPE) != GLFW_PRESS && !glfwWindowShouldClose(window)) {
        glClear(GL_COLOR_BUFFER_BIT); // Clear the screen
        glfwSwapBuffers(window); // Swap buffers
        glfwPollEvents();
    }
    
    glfwTerminate();
    return 0;
}
