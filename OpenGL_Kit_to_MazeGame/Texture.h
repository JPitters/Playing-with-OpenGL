//#pragma once
#ifndef TEXTURE_H
#define TEXTURE_H

#include "SceneNode.h"
#include <string>

//How can you access SceneNode without SceneNode including Texture

class Texture
{
	//int numTextures; //The number of Textures that are being applied to objects
	unsigned char* image; //The image that will be loaded from the file
	GLint width, height; //Dimensions for the loading image
	//static unsigned int* texPtr; // The pointer to the texture in memory

public:
	Texture();
	Texture(const char* file);
	void Texture::instantiate();
	void Texture::apply(SceneNode* );

};

#endif