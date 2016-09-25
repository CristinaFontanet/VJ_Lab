#ifndef _SCENE_INCLUDE
#define _SCENE_INCLUDE


#include <glm/glm.hpp>
#include "ShaderProgram.h"
#include "Quad.h"
#include "TexturedQuad.h"
#include "Text.h"


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
	void canviTextBolet();
	void marioUp();
	void marioDown();
	void marioLeft();
	void marioRight();

private:
	void initShaders();

private:
	Quad *cel;
	Texture texs[2];
	TexturedQuad *texQuad[4];
	ShaderProgram simpleProgram, texProgram;
	float currentTime;
	glm::mat4 projection;
	Text text;


	int windowHeight;
	int windowWidth;


	int posyMario = 48;
	int posxMario = 384;

	bool boletDreta = false;
	int posxBolet;
	int boletWidth = 128;


	int rebots = 0;
	bool showBoletText = true;

};


#endif // _SCENE_INCLUDE

