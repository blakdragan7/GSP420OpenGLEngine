#include <fstream>
#include <sstream>
#include <iostream>
#include "Vector2D.hpp"
#include <vector>

#include "GL/glew.h"
#include "helper.h"

#ifndef _WIN32
typedef struct tagBITMAPFILEHEADER {
    unsigned short    bfType;
    unsigned long     bfSize;
    unsigned short    bfReserved1;
    unsigned short    bfReserved2;
    unsigned long     bfOffBits;
} BITMAPFILEHEADER;

typedef struct tagBITMAPINFOHEADER{
    unsigned long		 biSize;
    long				 biWidth;
    long				 biHeight;
    unsigned short       biPlanes;
    unsigned short       biBitCount;
    unsigned long		 biCompression;
    unsigned long		 biSizeImage;
    long				 biXPelsPerMeter;
    long				 biYPelsPerMeter;
    unsigned long		 biClrUsed;
    unsigned long		 biClrImportant;
} BITMAPINFOHEADER;
#endif
namespace helper
{
	std::vector<std::string> &split(const std::string &s, char delim, std::vector<std::string> &elems) {
		std::stringstream ss(s);
		std::string item;
		while (std::getline(ss, item, delim)) {
			elems.push_back(item);
		}
		return elems;
	}


std::vector<std::string> split(const std::string &s, char delim) {
    std::vector<std::string> elems;
    split(s, delim, elems);
    return elems;
}

	unsigned int stringToInt(const char* string)
	{
		unsigned int x;
		std::stringstream ss;
		ss << string;
		ss >> x;
		return x;
	}
    
	unsigned int hexStringToInt(const char* hexString)
	{
		unsigned int x;
		std::stringstream ss;
		ss << std::hex << hexString;
		ss >> x;
		return x;
	}
    
	std::string intToString(int num)
	{
		std::string str;
		std::stringstream ss;
		ss << num;
		ss >> str;
		return str;
	}

	std::string doubleToString(double num)
	{
		std::string str;
		std::stringstream ss;
		ss << num;
		ss >> str;
		return str;
	}
    
	std::string hexToString(int hex)
	{
		std::string str;
		std::stringstream ss;
		ss << std::hex << hex;
		ss >> str;
		return str;
	}

	double	hmin(double x,double y)
	{
		if(x < y)
			return x;
		return y;
	}

	float	hmin(float x,float y)
	{
		if(x < y)
			return x;
		return y;
	}

	int		hmin(int x,int y)
	{
		if(x < y)
			return x;
		return y;
	}

	long	hmin(long x,long y)
	{
		if(x < y)
			return x;
		return y;
	}

	double	hmax(double x,double y)	
	{
		if(x > y)
			return x;
		return y;
	}

	float	hmax(float x,float y)
	{
		if(x > y)
			return x;
		return y;
	}

	int		hmax(int x,int y)
	{
		if(x > y)
			return x;
		return y;
	}

	long	hmax(long x,long y)
	{
		if(x > y)
			return x;
		return y;
	}
    
	unsigned int createGLTexture(const char* path)
	{
		unsigned int w;
		unsigned int h;
        
		std::fstream hFile(path, std::ios::in | std::ios::binary);
		if (!hFile.is_open()) throw std::invalid_argument("Error: File Not Found.");
        
		hFile.seekg(0, std::ios::end);
		int Length = (int)hFile.tellg();
		hFile.seekg(0, std::ios::beg);
		std::vector<BYTE> FileInfo(Length);
		hFile.read(reinterpret_cast<char*>(FileInfo.data()), 54);
        
		if(FileInfo[0] != 'B' && FileInfo[1] != 'M')
		{
			hFile.close();
			throw std::invalid_argument("Error: Invalid File Format. Bitmap Required.");
		}
        
		if (FileInfo[28] != 24 && FileInfo[28] != 32)
		{
			hFile.close();
			throw std::invalid_argument("Error: Invalid File Format. 24 or 32 bit Image Required.");
		}
        
		short BitsPerPixel = FileInfo[28];
		w = FileInfo[18] + (FileInfo[19] << 8);
		h = FileInfo[22] + (FileInfo[23] << 8);
		
		unsigned int PixelsOffset = FileInfo[10] + (FileInfo[11] << 8);
		unsigned int size = ((w * BitsPerPixel + 31) / 32) * 4 * h;
        
		std::vector<unsigned char> Pixels;
		Pixels.resize(size);
        
		hFile.seekg (PixelsOffset, std::ios::beg);
		hFile.read(reinterpret_cast<char*>(Pixels.data()), size);
		hFile.close();
        
		char* data = (char*)Pixels.data();
        
		unsigned int texture;
        
		glGenTextures(1, &texture);             // Generate a texture
		glBindTexture(GL_TEXTURE_2D, texture); // Bind that texture temporarily
        
		GLint mode = GL_RGB;                   // Set the mode
        
		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
        
		// Create the texture. We get the offsets from the image, then we use it with the image's
		// pixel data to create it.
		glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB, w, h, 0, GL_BGR, GL_UNSIGNED_BYTE, data);
        
		// Unbind the texture
		glBindTexture(GL_TEXTURE_2D, NULL);
        
		return texture;
	}
    
	void* loadBMP(const char* path,unsigned int *width,unsigned int *height)
	{
		std::fstream hFile(path, std::ios::in | std::ios::binary);
		if (!hFile.is_open()) throw std::invalid_argument("Error: File Not Found.");
        
		hFile.seekg(0, std::ios::end);
		int Length = (int)hFile.tellg();
		hFile.seekg(0, std::ios::beg);
		std::vector<BYTE> FileInfo(Length);
		hFile.read(reinterpret_cast<char*>(FileInfo.data()), 54);
        
		if(FileInfo[0] != 'B' && FileInfo[1] != 'M')
		{
			hFile.close();
			throw std::invalid_argument("Error: Invalid File Format. Bitmap Required.");
		}
        
		if (FileInfo[28] != 24 && FileInfo[28] != 32)
		{
			hFile.close();
			throw std::invalid_argument("Error: Invalid File Format. 24 or 32 bit Image Required.");
		}
        
		short BitsPerPixel = FileInfo[28];
		*width = FileInfo[18] + (FileInfo[19] << 8);
		*height = FileInfo[22] + (FileInfo[23] << 8);
		
		unsigned int PixelsOffset = FileInfo[10] + (FileInfo[11] << 8);
		unsigned int size = ((*width * BitsPerPixel + 31) / 32) * 4 * *height;
        
		std::vector<unsigned char> Pixels;
		Pixels.resize(size);
        
		hFile.seekg (PixelsOffset, std::ios::beg);
		hFile.read(reinterpret_cast<char*>(Pixels.data()), size);
		hFile.close();
        
		char* data = (char*)Pixels.data();
        
		//for(int i=0;i<Pixels.size();i++)
		//{
		//	std::cout << (unsigned int)data[i] << std::endl;
		//}
        
		return data;
	}
    
	bool addShaderFromConst(const char* constShader,GLenum type,GLuint program)
	{
		GLuint shader = glCreateShader(type);
		glShaderSource(shader,1,&constShader,NULL);
		glCompileShader(shader);
        
		GLint isCompiled = 1;
		glGetShaderiv(shader, GL_COMPILE_STATUS, &isCompiled);
		if(isCompiled == GL_FALSE)
		{
			GLint maxLength = 0;
			glGetShaderiv(shader, GL_INFO_LOG_LENGTH, &maxLength);
            
			//The maxLength includes the NULL character
			char* infoLog = new char[maxLength];
			glGetShaderInfoLog(shader, maxLength, &maxLength, &infoLog[0]);
			std:: cout << "Shader Compile Error: "<<infoLog << std::endl;
			return false;
		}
		glAttachShader(program,shader);
		return true;
	}
    
	bool addShaderFromFile(const char* file,GLenum type,GLuint program)
	{
		std::fstream File;
		File.open(file,std::ios::in);
		bool good = File.good();
		if(!good)
		{
			std::cout << "Error File not found: " << file << std::endl;
			return false;
		}
		std::string cs;
		File.seekg(0,std::ios::end);
		cs.resize((unsigned int)File.tellg());
		File.seekg(0,std::ios::beg);
		File.read(&cs[0],cs.size());
		File.close();
		const char* temp = cs.c_str();
		GLuint shader = glCreateShader(type);
		glShaderSource(shader,1,&temp,NULL);
		glCompileShader(shader);
        
		GLint isCompiled = 1;
		glGetShaderiv(shader, GL_COMPILE_STATUS, &isCompiled);
		if(isCompiled == GL_FALSE)
		{
			GLint maxLength = 0;
			glGetShaderiv(shader, GL_INFO_LOG_LENGTH, &maxLength);
            
			//The maxLength includes the NULL character
			GLchar* infoLog = new GLchar[maxLength];
			glGetShaderInfoLog(shader, maxLength, &maxLength, &infoLog[0]);
			std:: cout << "Shader Compile Error: "<<infoLog << std::endl;
			return false;
		}
		glAttachShader(program,shader);
		glDeleteShader(shader);
		return true;
	}
    
	bool linkProgram(GLuint program)
	{
		GLint status=GL_FALSE;
		glLinkProgram(program);
		glGetProgramiv(program,GL_LINK_STATUS,&status);
		if(status == GL_FALSE)
		{
			GLint maxLength = 0;
			glGetProgramiv(program, GL_INFO_LOG_LENGTH, &maxLength);
            
			//The maxLength includes the NULL character
			GLchar* infoLog = new GLchar[maxLength];
			glGetProgramInfoLog(program, maxLength, &maxLength, &infoLog[0]);
			std:: cout << "Program Link Error: " << infoLog << std::endl;
			return false;
		}
		return true;
	}
    
	void clearGLErrors()
	{
		int error;
		while ((error = glGetError()) != GL_NO_ERROR) {
		}
	}
    
	void checkGlError(const char* glOperation) {
#ifdef _DEBUG
		int error;
		while ((error = glGetError()) != GL_NO_ERROR) {
			const GLubyte* errorS = gluErrorString(error);
			if(!errorS)
				errorS = (const GLubyte*)" ";
			std::cout << "Error " << glOperation << ": glError " << gluErrorString(error) << std::endl;
		}
#else
		return;
#endif

	}

	Vec2D normalizeCoord(double posx,double posy,int width,int height,int type)
	{
		if(type == WINDOW2GL)
		{
			double newx = (posx - ((double)width/2.0))/((double)width/2.0);
			double newy = -(posy - ((double)height/2.0))/((double)height/2.0);

			return Vec2D(newx,newy);
		}
		else if(type == FRAME2GL)
		{
			double newx = (posx - ((double)width/2.0))/((double)width/2.0);
			double newy = -(posy - ((double)height/2.0))/((double)height/2.0);

			return Vec2D(newx,newy);
		}
		else if (type == GL2WINDOW)
		{
			double newx = (posx * ((double)width/2.0)) + (((double)width/2.0));
			double newy = -(posy * ((double)height/2.0)) + (((double)height/2.0));

			return Vec2D(newx,newy);
		}
		else if (type == GL2FRAME)
		{
			double newx = (posx * ((double)width/2.0)) + (((double)width/2.0));
			double newy = -(posy * ((double)height/2.0)) + (((double)height/2.0));

			return Vec2D(newx,newy);
		}

		return Vec2D();
	}

};
