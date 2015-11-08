#pragma once
#include <memory>
#include <GL\glew.h>

class GLTexture 
{
	GLuint textureID;
	GLuint type;
	GLuint format;

	int width,height;
public:
	static GLTexture* GLTextureFromPNG(const char* png);

	GLTexture(int width,int height, unsigned char* buffer=0, GLuint formatFrom=GL_RGBA,GLuint formatTo=GL_RGBA, GLuint type=GL_UNSIGNED_BYTE);
	virtual ~GLTexture(void);

	void bindTexture(GLuint activeTexture);
	void unbindTexture(GLuint activeTexture);
	void update(int offset,GLuint type,unsigned char* buffer);

	GLuint getTexID();
	int	getNumberComponents();

	virtual void updateBK(double time){}
	virtual void updateGL(double time){}
	virtual void initializeGL(){}
};

