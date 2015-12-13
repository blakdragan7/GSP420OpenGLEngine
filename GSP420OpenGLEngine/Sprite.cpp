#include "Sprite.h"
#include "GLTexture.h"
#include "GLShaderProgram.h"
#include <GL\glew.h>

Sprite::Sprite(void) : DrawableObject()
{
	texture = 0;
	program = 0;

	shouldRenderTexture = false;
	shouldUseProgram = false;

	needsDelete = false;
	hasAlpha = false;
}

Sprite::Sprite(GLTexture* tex,GLShaderProgram* program) : DrawableObject()
{
	this->texture = tex;
	this->program = program;

	shouldRenderTexture = tex != 0;
	shouldUseProgram = program != 0;

	needsDelete = false;
	hasAlpha = false;
}

Sprite::Sprite(const char* file,GLShaderProgram* program) : DrawableObject()
{
	this->texture = GLTexture::GLTextureFromPNG(file);
	this->program = program;

	shouldRenderTexture = texture != 0;
	shouldUseProgram = program != 0;

	needsDelete = true;
	hasAlpha = false;
}

Sprite::~Sprite(void)
{
	if(needsDelete)
	{
		if(texture)delete this->texture;
	}
}

void Sprite::draw()
{

	glMatrixMode(GL_MODELVIEW); // Set The Current Matrix being modified (options are ModelView , Model, View, Projection, and Texture)

	glPushMatrix(); // Save Current Matrix and copy we only modify the copy

	// We use Matricies to translate rotate and scale the sprite instead of modifiy vertecie 
	// location becasue matrix multiplications are very faster and easier to store

	glTranslatef(position.x,position.y,0);	// Translate the ModelView
	glScalef(scale.x,scale.y,1.0);			// Scale The ModelView     
	glRotatef(rotation,0,0,1.0);			// we rotate on the z axis since it is only a 2D scene

	// Texture and Shader 

	if(texture && shouldRenderTexture)
		texture->bindTexture(GL_TEXTURE0); // binds the texture to slot 0

	if(program && shouldUseProgram) 
		program->useProgram(); // tells opengl to use our custom shader
	else
		glUseProgram(0); // Sets the current shader program to the default program

	if(hasAlpha)
	{
		glEnable(GL_BLEND);
		glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
	}

	glBegin(GL_QUADS); // Begin Drawing QUADS

	// Drawing is done in a counter clockwise order because openGl CULLS (doesnt render) 
	// things going in a clockwise direction as they are assumed to be facing away from the camera

	glColor3f(blendR,blendG,blendB); // Blend Color

	glTexCoord2f(0,0);		// Bottm Left
		glVertex2f(-1,1); 
	glTexCoord2f(1,0);		// Bottom Right
		glVertex2f( 1,1); 
	glTexCoord2f(1,1);		// Top Right
		glVertex2f( 1, -1); 
	glTexCoord2f(0,1);		// Top Left
		glVertex2f(-1, -1); 

	glEnd(); // Single To OpenGL that this opbject is finished being drawn

	if(hasAlpha)
	{
		glDisable(GL_BLEND);
	}

	glPopMatrix(); // Return To the previous copy of the matric before it was modified here

}

void Sprite::update(float dt)
{

	 // This is where any updating would occure (ex physics life check etc.. )
	//  This can and should be overriden in a sub class 

}

void Sprite::setAlpha(bool alpha)
{
	hasAlpha=alpha;
}