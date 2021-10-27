#pragma once

#include "SDL.h"

#include "CTextureManager.h"

#include <iostream>
#include <string>
#include <fstream>

const int WWIDTH = 1200;
const int WHEIGHT = 880;

const int SIZETILE = 80;

using namespace std;

class CGame {
private:
	bool bRunning;

	SDL_Window* pWindow;
	SDL_Renderer* pRenderer;

	CTextureManager textureManager;

	int map [WHEIGHT / SIZETILE][WWIDTH / SIZETILE];
	int deco[WHEIGHT / SIZETILE][WWIDTH / SIZETILE];



public:
	//Constructeur
	CGame();

	//Destructeur
	~CGame();

	//Framework
	bool init(const char* title, int xpos, int ypos, int flags);
	void render();
	void update();
	void handleEvents();
	void clean();

	//Accesseurs
	bool getBRunning();

	//Mutateurs
	void setBRunning(bool bRunning);

protected:

};
