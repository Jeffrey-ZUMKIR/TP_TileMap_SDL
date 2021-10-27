#pragma once

#include "SDL.h"
#include "SDL_image.h"

#include <iostream>
#include <map>

class CTextureManager {
private:
	std::map<std::string, SDL_Texture*> m_textureMap;

public:
	//Constructeur
	CTextureManager();

	//Destructeur
	~CTextureManager();


	//Load image
	bool loadPNG(std::string fileName, std::string id, SDL_Renderer* pRenderer);

	// draw
	void drawPNG(std::string id, int x, int y, int width, int height, SDL_Renderer* pRenderer, SDL_RendererFlip flip = SDL_FLIP_NONE);
	void drawTile(std::string id, int x, int y, int width, int height, SDL_Renderer* pRenderer, int nbTile, int widthTM, SDL_RendererFlip flip = SDL_FLIP_NONE);
protected:
};
