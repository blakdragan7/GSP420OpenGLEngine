#ifndef HELPER_H
#define HELPER_H

#include <string>
#include <vector>

#ifdef _WIN32

#include <windows.h>

#else

#include <sys/time.h>

#endif

#include "Vector2D.hpp"

#define SecToMil(a) a*1000
#define WINDOW2GL 0
#define FRAME2GL 1
#define GL2WINDOW 2
#define GL2FRAME 3

namespace helper
{
    
	extern bool linkProgram(unsigned int program);
	extern bool addShaderFromFile(const char* file,unsigned int type,unsigned int program);
	extern bool addShaderFromConst(const char* constShader,unsigned int type,unsigned int program);
    
	extern void checkGlError(const char* glOperation);
	extern void clearGLErrors();
    
	extern std::vector<std::string> &split(const std::string &s, char delim, std::vector<std::string> &elems);
	extern unsigned int stringToInt(const char* string);
	extern unsigned int hexStringToInt(const char* hexString);
	extern std::string intToString(int num);
	extern std::string hexToString(int hex);
	extern std::string doubleToString(double num);
    
	extern double	hmin(double x,double y);
	extern float	hmin(float x,float y);
	extern int		hmin(int x,int y);
	extern long		hmin(long x,long y);

	extern double	hmax(double x,double y);
	extern float	hmax(float x,float y);
	extern int		hmax(int x,int y);
	extern long		hmax(long x,long y);

	extern unsigned int createGLTexture(const char* path);
	extern void* loadBMP(const char* path,unsigned int *width,unsigned int *height);
	extern Vec2D normalizeCoord(double posx,double posy,int width,int height,int type = 0);
};
#endif