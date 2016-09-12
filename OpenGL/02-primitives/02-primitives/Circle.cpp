#include <GL/glew.h>
#include <GL/glut.h>
#include "Circle.h"

Circle *Circle::createCircle(float x, float y, float width, float height, ShaderProgram &program)
{
	Circle *circle = new Circle(x, y, width, height, program);

	return circle;
}


Circle::Circle(float x, float y, float width, float height, ShaderProgram &program)
{
	float vertices[12] = { x, y, x + width, y,
		x + width, y + width,
		x, y, x + width, y + width,
		x, y + width };

	glGenVertexArrays(1, &vao);
	glBindVertexArray(vao);
	glGenBuffers(1, &vbo);
	glBindBuffer(GL_ARRAY_BUFFER, vbo);
	glBufferData(GL_ARRAY_BUFFER, 12 * sizeof(float), vertices, GL_STATIC_DRAW);
	posLocation = program.bindVertexAttribute("position", 2);


}

void Circle::render() const
{
	glBindVertexArray(vao);
	glEnableVertexAttribArray(posLocation);
	glDrawArrays(GL_POLYGON, 0, 4);
}

void Circle::free()
{
	glDeleteBuffers(1, &vbo);
}

