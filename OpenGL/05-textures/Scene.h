#ifndef _SCENE_INCLUDE
#define _SCENE_INCLUDE


#include <glm/glm.hpp>
#include "ShaderProgram.h"
#include "Quad.h"
#include "TexturedQuad.h"


#define CAMERA_WIDTH 640
#define CAMERA_HEIGHT 480


// Scene contains all the entities of our game.
// It is responsible for updating and render them.


class Scene
{

public:
	Scene();
	~Scene();

	void init();
	void update(int deltaTime);
	void render();
	void marioUp();
	void marioDown();

private:
	void initShaders();

private:
	Quad *cel;
	Texture texs[3];
	TexturedQuad *texQuad[4];
	ShaderProgram simpleProgram, texProgram;
	float currentTime;
	glm::mat4 projection;

	int maxRange = 210;
	int posyMario = 48;
	int currentRange = 0;
};


#endif // _SCENE_INCLUDE

