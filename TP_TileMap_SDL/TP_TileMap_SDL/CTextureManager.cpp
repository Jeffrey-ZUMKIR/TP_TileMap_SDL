#include "CTextureManager.h"

CTextureManager::CTextureManager()
{

}

CTextureManager::~CTextureManager()
{
}


//GOAL	: Load a PNG image with an ID in the list
bool CTextureManager::loadPNG(std::string fileName, std::string id, SDL_Renderer* pRenderer)
{
	SDL_Surface* pTempSurface = IMG_Load(fileName.c_str());
	if (pTempSurface == 0) {
		return false;
	}

	SDL_Texture* pTexture = SDL_CreateTextureFromSurface(pRenderer, pTempSurface);
	SDL_FreeSurface(pTempSurface);

	if (pTexture != 0) {
		m_textureMap[id] = pTexture;
		return true;
	}
	return false;
}

//GOAL	: Display the texture
void CTextureManager::drawPNG(std::string id, int x, int y, int width, int height, SDL_Renderer* pRenderer, SDL_RendererFlip flip)
{
	SDL_Rect destRect;

	destRect.w = width;
	destRect.h = height;
	destRect.x = x;
	destRect.y = y;
	SDL_RenderCopyEx(pRenderer, m_textureMap[id], NULL, &destRect, 0, 0, flip);
}

//GOAL	: Display tile
void CTextureManager::drawTile(std::string id, int x, int y, int width, int height, SDL_Renderer* pRenderer, int nbTile, SDL_RendererFlip flip)
{
	SDL_Rect destRect;
	SDL_Rect srcRect;

	destRect.w = srcRect.w = width;
	destRect.h = srcRect.h = height;
	destRect.x = x*width;
	destRect.y = y*width;
	//Get the correct tile
	srcRect.x = (nbTile % 3) * width;
	srcRect.y = nbTile / 3 * width;
	
	SDL_RenderCopyEx(pRenderer, m_textureMap[id], &srcRect, &destRect, 0, 0, flip);
}