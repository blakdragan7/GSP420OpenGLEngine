#pragma once
#include "Vector2D.hpp"
#ifndef GLuint
typedef unsigned int GLuint;
#endif

#ifndef BYTE
typedef unsigned char BYTE;
#endif

class GLShaderProgram
{
private:
	GLuint program;

public:
	GLShaderProgram(const char* vert_shader,const char* frag_shader);
	~GLShaderProgram(void);

	void createProgramFromConst(const char* vert_shader,const char* frag_shader);

	void useProgram();
	void detatchprogram();

	void setUniform(const char* uniform,int value);
	void setUniform(const char* uniform,float value);
	void setUniform(const char* uniform,double value);
	void setUniform(const char* uniform,Vec2F value);
};

