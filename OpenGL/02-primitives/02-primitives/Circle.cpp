#include <GL/glew.h>
#include <GL/glut.h>
#include "Circle.h"
#define _USE_MATH_DEFINES
#include <math.h>

Circle *Circle::createCircle(float x, float y, float radius, ShaderProgram &program)
{
	Circle *circle = new Circle(x, y, radius, program);

	return circle;
}


Circle::Circle(float x, float y, float radius, ShaderProgram &program)
{
							 //GLfloat radius = 0.8f; //radius
	GLfloat twicePi = 2.0f * (GLfloat)M_PI;

	float vert[triangleAmount*2+2];
	vert[0] = x;
	vert[1] = y;
	int pos = 2;
	for (int i = 0; i <= triangleAmount; i++) {
		vert[pos] = x + (radius * cos(i *  twicePi / triangleAmount));
		vert[pos+1] = y + (radius * sin(i * twicePi / triangleAmount));
		pos += 2;
	}

	glGenVertexArrays(1, &vao);
	glBindVertexArray(vao);
	glGenBuffers(1, &vbo);
	glBindBuffer(GL_ARRAY_BUFFER, vbo);
	glBufferData(GL_ARRAY_BUFFER, (triangleAmount*2+2) * sizeof(float), vert, GL_STATIC_DRAW);
	posLocation = program.bindVertexAttribute("position", 2); 



}

void Circle::render() const
{
	glBindVertexArray(vao);
	glEnableVertexAttribArray(posLocation);
	glDrawArrays(GL_TRIANGLE_FAN, 0, triangleAmount);
}

void Circle::free()
{
	glDeleteBuffers(1, &vbo);
}

