#include <iostream>
#include <cmath>
#include <glm/gtc/matrix_transform.hpp>
#include "Scene.h"
#include "Windows.h"
#include <GL/glut.h>


Scene::Scene()
{
	cel = NULL;
}

Scene::~Scene()
{
	if(cel != NULL)
		delete cel;
	for(int i=0; i<3; i++)
		if(texQuad[i] != NULL)
			delete texQuad[i];
}


void Scene::init() {
	//init vars
	windowHeight = glutGet(GLUT_WINDOW_HEIGHT);
	windowWidth = glutGet(GLUT_WINDOW_WIDTH);
	currentTime = 0.0f;

	// Load textures
	texs[0].loadFromFile("images/varied.png", TEXTURE_PIXEL_FORMAT_RGBA);
	texs[0].setMagFilter(GL_NEAREST);
	texs[1].loadFromFile("images/bricks.png", TEXTURE_PIXEL_FORMAT_RGBA);
	texs[1].setMagFilter(GL_NEAREST);
	//Objects
	glm::vec2 geom[2] = {glm::vec2(0.f, 0.f), glm::vec2(128.f, 128.f)};
	glm::vec2 texCoords[2] = {glm::vec2(0.f, 0.f), glm::vec2(1.f, 1.f)};

	initShaders();
	//cel
	cel = Quad::createQuad(0.f, 0.f, windowWidth, windowHeight, simpleProgram);
	//terra
	glm::vec2 geomTerra[2] = { glm::vec2(0.f, 0.f), glm::vec2(windowWidth, windowHeight/4) };
	texCoords[0] = glm::vec2(0.f, 0.f); texCoords[1] = glm::vec2(8.f, 2.f);
	texQuad[2] = TexturedQuad::createTexturedQuad(geomTerra, texCoords, texProgram);
	
	//mario
	texCoords[0] = glm::vec2(0.f, 0.f); texCoords[1] = glm::vec2(0.5f, 0.5f);
	texQuad[0] = TexturedQuad::createTexturedQuad(geom, texCoords, texProgram);
	//estrella
	texCoords[0] = glm::vec2(0.5f, 0.5f); texCoords[1] = glm::vec2(1.f, 1.f);
	texQuad[1] = TexturedQuad::createTexturedQuad(geom, texCoords, texProgram);
	//bolet
	texCoords[0] = glm::vec2(0.f, 0.5f); texCoords[1] = glm::vec2(0.5f, 1.f);
	texQuad[3] = TexturedQuad::createTexturedQuad(geom, texCoords, texProgram);


	// Load textures
	projection = glm::ortho(0.f, float(CAMERA_WIDTH - 1), float(CAMERA_HEIGHT - 1), 0.f);
	
	// Select which font you want to use
	if(!text.init("fonts/OpenSans-Regular.ttf"))
	//if(!text.init("fonts/OpenSans-Bold.ttf"))
	//if(!text.init("fonts/DroidSerif.ttf"))
		cout << "Could not load font!!!" << endl;
}

void Scene::update(int deltaTime)
{
	currentTime += deltaTime;
}

void Scene::render()
{
	glm::mat4 modelview;

	simpleProgram.use();
	simpleProgram.setUniformMatrix4f("projection", projection);
//cel
	simpleProgram.setUniform4f("color", 0.53f, 0.8f, 0.98f, 1.f);
	simpleProgram.setUniformMatrix4f("modelview", modelview);
	cel->render();

	texProgram.use();
	texProgram.setUniformMatrix4f("projection", projection);
	texProgram.setUniform4f("color", 1.0f, 1.0f, 1.0f, 1.0f);
	//terra
	modelview = glm::translate(glm::mat4(1.0f), glm::vec3(0.f, 397.f, 0.f));
	texProgram.setUniformMatrix4f("modelview", modelview);
	texQuad[2]->render(texs[1]);
	//Mario
	modelview = glm::translate(glm::mat4(1.0f), glm::vec3(384.f, posyMario, 0.f));
	texProgram.setUniformMatrix4f("modelview", modelview);
	texQuad[0]->render(texs[0]);
	//Estrella
	modelview = glm::translate(glm::mat4(1.0f), glm::vec3(128.f, 150.f, 0.f));
	modelview = glm::translate(modelview, glm::vec3(64.f, 64.f, 0.f));
	modelview = glm::rotate(modelview, currentTime / 1000.f, glm::vec3(0.0f, 0.0f, 1.0f));
	modelview = glm::translate(modelview, glm::vec3(-64.f, -64.f, 0.f));
	texProgram.setUniformMatrix4f("modelview", modelview);
	texQuad[1]->render(texs[0]);
	//Bolet
	modelview = glm::translate(glm::mat4(1.0f), glm::vec3(280.f + currentRange, 300.f, 0.f));
	texProgram.setUniformMatrix4f("modelview", modelview);
	texQuad[3]->render(texs[0]);

//Text

	text.render("Videogames!!!", glm::vec2(10, CAMERA_HEIGHT-20), 32, glm::vec4(1, 1, 1, 1));

}

void Scene::initShaders()
{
	Shader vShader, fShader;

	vShader.initFromFile(VERTEX_SHADER, "shaders/simple.vert");
	if(!vShader.isCompiled())
	{
		cout << "Vertex Shader Error" << endl;
		cout << "" << vShader.log() << endl << endl;
	}
	fShader.initFromFile(FRAGMENT_SHADER, "shaders/simple.frag");
	if(!fShader.isCompiled())
	{
		cout << "Fragment Shader Error" << endl;
		cout << "" << fShader.log() << endl << endl;
	}
	simpleProgram.init();
	simpleProgram.addShader(vShader);
	simpleProgram.addShader(fShader);
	simpleProgram.link();
	if(!simpleProgram.isLinked())
	{
		cout << "Shader Linking Error" << endl;
		cout << "" << simpleProgram.log() << endl << endl;
	}
	simpleProgram.bindFragmentOutput("outColor");

	vShader.free();
	fShader.free();
	vShader.initFromFile(VERTEX_SHADER, "shaders/texture.vert");
	if(!vShader.isCompiled())
	{
		cout << "Vertex Shader Error" << endl;
		cout << "" << vShader.log() << endl << endl;
	}
	fShader.initFromFile(FRAGMENT_SHADER, "shaders/texture.frag");
	if(!fShader.isCompiled())
	{
		cout << "Fragment Shader Error" << endl;
		cout << "" << fShader.log() << endl << endl;
	}
	texProgram.init();
	texProgram.addShader(vShader);
	texProgram.addShader(fShader);
	texProgram.link();
	if(!texProgram.isLinked())
	{
		cout << "Shader Linking Error" << endl;
		cout << "" << texProgram.log() << endl << endl;
	}
	texProgram.bindFragmentOutput("outColor");
}

