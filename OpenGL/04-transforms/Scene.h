#ifndef _SCENE_INCLUDE
#define _SCENE_INCLUDE


#include <glm/glm.hpp>
#include "ShaderProgram.h"
#include "Quad.h"


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

private:
	void initShaders();

private:
	Quad *quad;
	ShaderProgram program;
	float currentTime;
	glm::mat4 projection;

	int maxRange = 64;
	int currentRange = 0;
	float maxSF = 0.75f;
	float sf = 0.0f;

	float xquad = -50;
	float maxX = -50;
	float tam = 1;
	float progresion = 100;
};


#endif // _SCENE_INCLUDE

