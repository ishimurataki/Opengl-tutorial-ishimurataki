//
//  controls.hpp
//  opengl-learning
//
//  Created by Takanao Ishimura on 6/18/23.
//

#ifndef controls_hpp
#define controls_hpp

#include <stdio.h>
#include <GL/glew.h>
#include <GLFW/glfw3.h>
#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
using namespace glm;

mat4 getViewMatrix();
mat4 getProjectionMatrix();
void computeMatricesFromInputs(GLFWwindow* window);

#endif /* controls_hpp */
