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
}

Sprite::Sprite(GLTexture* tex,GLShaderProgram* program) : DrawableObject()
{
	this->texture = tex;
	this->program = program;

	shouldRenderTexture = tex != 0;
	shouldUseProgram = program != 0;
}

Sprite::Sprite(const char* file,GLShaderProgram* program) : DrawableObject()
{
	this->texture = GLTexture::GLTextureFromPNG(file);
	this->program = program;

	shouldRenderTexture = texture != 0;
	shouldUseProgram = program != 0;

}

Sprite::~Sprite(void)
{
	// We dont de allocate the texture becasue that will be the texture managers job
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

	glBegin(GL_QUADS); // Begin Drawing QUADS

	// Drawing is done in a counter clockwise order because openGl CULLS (doesnt render) 
	// things going in a clockwise direction as they are assumed to be facing away from the camera

	glTexCoord2f(0,0);
		glVertex2f(-1,-1); // Bottm Left
	glTexCoord2f(1,0);
		glVertex2f( 1,-1); // Bottom Right
	glTexCoord2f(1,1);
		glVertex2f( 1, 1); // Top Right
	glTexCoord2f(0,1);
		glVertex2f(-1, 1); // Top Left

	glEnd(); // Single To OpenGL that this opbject is finished being drawn

	glPopMatrix(); // Return To the previous copy of the matric before it was modified here
}

void Sprite::update(float dt)
{
	 // This is where any updating would occure (ex physics life check etc.. )
	//  This can and should be overriden in a sub class 
}