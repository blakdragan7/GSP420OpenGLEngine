#include "GL\glew.h"
#include "helper.h"
#include "GLShaderProgram.h"
#include <iostream>


GLShaderProgram::GLShaderProgram(const char* vert_shader,const char* frag_shader)
{
	program = glCreateProgram();
	if(!vert_shader && !frag_shader)
		return;

	if(vert_shader)
	{
		helper::addShaderFromFile(vert_shader,GL_VERTEX_SHADER,program);
	}
	if(frag_shader)
	{
		helper::addShaderFromFile(frag_shader,GL_FRAGMENT_SHADER,program);
	}

	helper::linkProgram(program);
}

GLShaderProgram::~GLShaderProgram(void)
{
	glDeleteProgram(program);
}

void GLShaderProgram::createProgramFromConst(const char* vert_shader,const char* frag_shader)
{
	if(vert_shader)
	{
		helper::addShaderFromConst(vert_shader,GL_VERTEX_SHADER,program);
	}
	if(frag_shader)
	{
		helper::addShaderFromConst(frag_shader,GL_FRAGMENT_SHADER,program);
	}

	helper::linkProgram(program);
}

void GLShaderProgram::useProgram()
{
	glUseProgram(program);
	helper::checkGlError("UseProgram");
}

void GLShaderProgram::detatchprogram()
{
	glUseProgram(0);
}

void GLShaderProgram::setUniform(const char* uniform,int value)
{
	helper::clearGLErrors();
	GLuint loc = glGetUniformLocation(program,uniform);
	glUniform1i(loc,value);
	helper::checkGlError("setUniform");
}

void GLShaderProgram::setUniform(const char* uniform,float value)
{
	helper::clearGLErrors();
	GLuint loc = glGetUniformLocation(program,uniform);
	glUniform1f(loc,value);
	helper::checkGlError("setUniform");
}

void GLShaderProgram::setUniform(const char* uniform,double value)
{
	helper::clearGLErrors();
	GLuint loc = glGetUniformLocation(program,uniform);
	glUniform1d(loc,value);
	helper::checkGlError("setUniform");
}

void GLShaderProgram::setUniform(const char* uniform,Vec2F value)
{
	helper::clearGLErrors();
	GLuint loc = glGetUniformLocation(program,uniform);
	glUniform2f(loc,value.x,value.y);
	helper::checkGlError("setUniform");
}