//
//  bitmap.cpp
//  opengl-learning
//
//  Created by Takanao Ishimura on 6/18/23.
//

#include "bitmap.hpp"

GLuint loadBMP_custom(const char* imagePath) {
    // Data read from the header of the BMP file
    unsigned char header[54]; // Each BMP begins with 54 bit header
    unsigned int dataPos;
    unsigned int width, height;
    unsigned int imageSize;
    unsigned char* data;
    
    // Open file
    FILE* file = fopen(imagePath, "rb");
    if (!file) {
        printf("Image could not be openned\n");
        return 0;
    }
    if (fread(header, 1, 54, file) != 54 || header[0] != 'B' || header[1] != 'M') {
        printf("Not a correct BMP file\n");
        return 0;
    }
    
    // Read ints from the header
    dataPos = *(int*)&(header[0x0A]);
    imageSize = *(int*)&(header[0x22]);
    width = *(int*)&(header[0x12]);
    height = *(int*)&(header[0x16]);
    
    // Some BMPs are misformatted - if so, guess missing information
    if (imageSize == 0) imageSize = width * height * 3;
    if (dataPos == 0) dataPos = 54;
    
    // Create a buffer and read data into buffer
    data = new unsigned char[imageSize];
    fread(data, 1, imageSize, file);
    fclose(file);
    
    // Create one OpenGL texture
    GLuint textureID;
    glGenTextures(1, &textureID);
    
    // 'Bind' the newly created texture
    glBindTexture(GL_TEXTURE_2D, textureID);
    
    // Give the image to openGL
    glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB, width, height, 0, GL_BGR, GL_UNSIGNED_BYTE, data);
    
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR_MIPMAP_LINEAR);
    glGenerateMipmap(GL_TEXTURE_2D);
    
    return textureID;
}
