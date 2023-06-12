//
//  shader.hpp
//  opengl-learning
//
//  Created by Takanao Ishimura on 6/11/23.
//
 
#ifndef shader_hpp
#define shader_hpp

#include <stdio.h>
#include <string>
#include <iostream>
#include <fstream>
#include <sstream>
#include <GL/glew.h>

GLuint LoadShaders(const char * vertex_file_path,const char * fragment_file_path);

#endif /* shader_hpp */
