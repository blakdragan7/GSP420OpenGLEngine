#include <vector>
#include <string>
#include <iostream>
#include "lodepng\lodepng.h"
#include "GLTexture.h"

GLTexture* GLTexture::GLTextureFromPNG(const char* png)
{
	std::string file(png);
	std::vector<unsigned char> image;
	unsigned width, height;
	unsigned error = lodepng::decode(image, width, height, file);

	if(error != 0)
	{
		std::cout << "error " << error << ": " << lodepng_error_text(error) << std::endl;
		return 0;
	}

	return new GLTexture(width,height,&image[0]);
}
GLTexture::GLTexture(int width_,int height_, unsigned char* buffer, GLuint formatFrom,GLuint formatTo, GLuint type_)
{
	width = width_;
	height = height_;
	type = type_;
	format = formatTo;

	glGenTextures(1,&textureID);
	glBindTexture(GL_TEXTURE_2D,textureID);

	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_CLAMP);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_CLAMP);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);

	glTexImage2D(GL_TEXTURE_2D,0,format,width,height,0,formatFrom,type,buffer);

	glBindTexture(GL_TEXTURE_2D,0);
}

GLTexture::~GLTexture(void)
{
	glDeleteTextures(1,&textureID);
}

void GLTexture::bindTexture(GLuint activeTexture)
{
	glActiveTexture(activeTexture);
	glBindTexture(GL_TEXTURE_2D,textureID);
}

void GLTexture::unbindTexture(GLuint activeTexture)
{
	glActiveTexture(activeTexture);
	glBindTexture(GL_TEXTURE_2D,0);
}

void GLTexture::update(int offset,GLuint type_,unsigned char* buffer)
{
	glBindTexture(GL_TEXTURE_2D,textureID);
	glTexSubImage2D(GL_TEXTURE_2D,0,0,0,width,height,format,type_,buffer);
	glBindTexture(GL_TEXTURE_2D,0);
}

GLuint GLTexture::getTexID()
{
	return textureID;
}

int	GLTexture::getNumberComponents()
{
	switch(format)
	{
	case GL_LUMINANCE:
	case GL_BLUE:
	case GL_GREEN:
	case GL_RED:
		return 1;
		break;
	case GL_RG:
		return 2;
		break;
	case GL_RGB:
	case GL_BGR:
		return 3;
		break;
	case GL_BGRA:
	case GL_RGBA:
		return 4;
		break;
	default:
		return -1;
		break;
	}
	return -1;
}