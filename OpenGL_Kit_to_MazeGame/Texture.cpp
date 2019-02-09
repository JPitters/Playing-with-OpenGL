
/*
#include "Texture.h"
#include "SOIL.h"

#pragma once
//namespace Textured {

	Texture::Texture() {
		image = NULL;
		width = 0;
		height = 0;
	}

	Texture::Texture(const char* file) { //Maybe you need to add the other variables like texPtr and numTex by referene
		texPtr = new GLuint[++numTex];
		image = SOIL_load_image(file, &width, &height, 0, SOIL_LOAD_RGB);
	}

	void Texture::apply(SceneNode* obj)
	{
		//This function needs to get a primitive as a parameter, but how can one include the class, without the class calling Texture.h

		//Square* temp = obj;

		obj->saveTex(this);
		

	}

	void Texture::instantiate()
	{
		glBindTexture(GL_TEXTURE_2D, texPtr[(numTex-1)]);
		glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB, width, height, 0, GL_RGB, GL_UNSIGNED_BYTE, image);
		glTexParameterf(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
		glTexParameterf(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
		glTexParameterf(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_NEAREST);
		glTexParameterf(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_NEAREST);

	}*/
//}




