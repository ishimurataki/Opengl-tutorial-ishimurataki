//
//  controls.cpp
//  opengl-learning
//
//  Created by Takanao Ishimura on 6/18/23.
//

#include "controls.hpp"
mat4 viewMatrix;
mat4 projectionMatrix;

mat4 getViewMatrix() {
    return viewMatrix;
}

mat4 getProjectionMatrix() {
    return projectionMatrix;
}

// position
vec3 position = vec3(0, 0, 5);
// horizontal angle - toward -Z
float horizontalAngle = 3.14f;
// vertical angle
float verticalAngle = 0.0f;
// initial field of view
float initialFoV = 45.0f;

float speed = 5.0f;
float mouseSpeed = 0.005f;

void computeMatricesFromInputs(GLFWwindow* window) {
    // static time variable for timestamping last frame
    static double lastTime = glfwGetTime();
    
    // compute time difference between current and previous frame
    double currentTime = glfwGetTime();
    float deltaTime = currentTime - lastTime;
    
    // get mouse positition
    double xPos, yPos;
    glfwGetCursorPos(window, &xPos, &yPos);
    
    // get window width and height
    int windowWidth, windowHeight;
    glfwGetWindowSize(window, &windowWidth, &windowHeight);
    
    // reset mouse position for next frame
    glfwSetCursorPos(window, windowWidth / 2.0, windowHeight / 2.0);
    
    // compute new orientation
    horizontalAngle += mouseSpeed * float(windowWidth / 2.0 - xPos);
    verticalAngle   += mouseSpeed * float(windowHeight/ 2.0 - yPos);
    
    // direction - spherical to cartesian coordinates
    vec3 direction = vec3(cos(verticalAngle) * sin(horizontalAngle),
                          sin(verticalAngle),
                          cos(verticalAngle) * cos(horizontalAngle));
    
    // right vector
    vec3 right = vec3(sin(horizontalAngle - 3.14f/2.0f),
                      0,
                      cos(horizontalAngle - 3.14f/2.0f));
    
    // up vector
    vec3 up = cross(right, direction);
    
    // move forward
    if (glfwGetKey(window, GLFW_KEY_W) == GLFW_PRESS) {
        position += deltaTime * direction * speed;
    }
    // move backward
    if (glfwGetKey(window, GLFW_KEY_S) == GLFW_PRESS) {
        position -= deltaTime * direction * speed;
    }
    // strafe left
    if (glfwGetKey(window, GLFW_KEY_A) == GLFW_PRESS) {
        position -= deltaTime * right * speed;
    }
    // strafe right
    if (glfwGetKey(window, GLFW_KEY_D) == GLFW_PRESS) {
        position += deltaTime * right * speed;
    }
    // move up
    if (glfwGetKey(window, GLFW_KEY_Q) == GLFW_PRESS) {
        position += deltaTime * vec3(0,1,0) * speed;
    }
    // move backward
    if (glfwGetKey(window, GLFW_KEY_E) == GLFW_PRESS) {
        position -= deltaTime * vec3(0,1,0) * speed;
    }
    
    // projection matrix
    projectionMatrix = perspective(initialFoV, (float)windowWidth / (float)windowHeight, 0.1f, 100.0f);
    
    // camera matrix
    viewMatrix = lookAt(position, position + direction, up);
    
    // set lastTime to current time for next frame
    lastTime = currentTime;
}
