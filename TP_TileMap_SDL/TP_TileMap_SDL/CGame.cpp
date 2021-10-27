#include "CGame.h"


CGame::CGame()
{
	bRunning = true;

	pWindow = NULL;
	pRenderer = NULL;

	for (int n_i = 0; n_i < WHEIGHT / 60; n_i++) {
		for (int n_j = 0; n_j < WWIDTH / 60; n_j++) {
			map[n_i][n_j] = 0;
		}
	}
}

CGame::~CGame()
{
}

bool CGame::init(const char* title, int xpos, int ypos, int flags)
{
	// attempt to initialize SDL
	if (SDL_Init(SDL_INIT_EVERYTHING) == 0) {
		std::cout << "SDL init success\n";
		// init the window
		pWindow = SDL_CreateWindow(title, xpos, ypos, WWIDTH, WHEIGHT, flags);
		// window initsuccess
		if (pWindow != 0) {
			std::cout << "window creation success\n";
			pRenderer = SDL_CreateRenderer(pWindow, -1, 0);
			// renderer init success
			if (pRenderer != 0) {
				std::cout << "renderer creation success\n";
				SDL_SetRenderDrawColor(pRenderer, 255, 255, 255, 255);
			}
			else
			{
				std::cout << "renderer init fail\n";
				return false; // renderer init fail
			}
		}
		else
		{
			std::cout << "window init fail\n";
			return false; // window init fail
		}
	}
	else
	{
		std::cout << "SDL init fail\n";
		return false; // SDL init fail
	}

	//Game is on
	bRunning = true;

	ifstream mymap;
	textureManager.loadPNG("./Assets/tileMap.png", "tile", pRenderer);
	mymap.open("Map.txt");

	//Get the information of the tile in the array
	for (int n_i = 0; n_i < 11; n_i++) {
		for (int n_j = 0; n_j < 15; n_j++) {
			mymap >> map[n_i][n_j];
		}
	}
	mymap.close();

	textureManager.loadPNG("./Assets/TM_Meuble.png", "deco", pRenderer);
	mymap.open("Deco.txt");

	//Get the information of the tile in the array
	for (int n_i = 0; n_i < 11; n_i++) {
		for (int n_j = 0; n_j < 15; n_j++) {
			mymap >> deco[n_i][n_j];
		}
	}
	mymap.close();


	std::cout << "init success\n";
}

void CGame::render()
{
	//Background
	SDL_SetRenderDrawColor(pRenderer, 0, 0, 0, 255);
	SDL_RenderClear(pRenderer); // clear the renderer to the draw color

	//Draw the tile
	for (int n_i = 0; n_i < 11; n_i++) {
		for (int n_j = 0; n_j < 15; n_j++) {
			textureManager.drawTile("tile", n_j, n_i, 80, 80, pRenderer, map[n_i][n_j], 3);
		}
	}

	for (int n_i = 0; n_i < 11; n_i++) {
		for (int n_j = 0; n_j < 15; n_j++) {
			textureManager.drawTile("deco", n_j, n_i, 80, 80, pRenderer, deco[n_i][n_j], 10);
		}
	}

	

	SDL_RenderPresent(pRenderer); // draw to the screen
}

void CGame::update()
{

}

void CGame::handleEvents()
{
	SDL_Event event;
	if (SDL_PollEvent(&event)) {
		switch (event.type) {
		case SDL_QUIT:
			bRunning = false;
			break;
		case SDL_KEYDOWN:
			switch (event.key.keysym.sym) {
			case SDLK_LEFT:
			case SDLK_q:
				break;
			case SDLK_RIGHT:
			case SDLK_d:
				break;
			case SDLK_SPACE:
				break;
			default:
				break;
			}
			break;
			//Input release
		case SDL_KEYUP:
			switch (event.key.keysym.sym) {
			case SDLK_LEFT:
			case SDLK_q:
			case SDLK_RIGHT:
			case SDLK_d:
				break;
			}
		default:
			break;
		}
	}
}

void CGame::clean()
{
	std::cout << "cleaning game\n";
	SDL_DestroyWindow(pWindow);
	SDL_DestroyRenderer(pRenderer);
	SDL_Quit();

}

bool CGame::getBRunning()
{
	return bRunning;
}

void CGame::setBRunning(bool bRunning)
{
	this->bRunning = bRunning;
}
