
#include "SDL.h"
#include "SDL_image.h"
#include "CGame.h"


int main(int argc, char** argv) {

	CGame game;

	game.init("Game", 100, 100, 0);

	while (game.getBRunning()) {
		game.handleEvents();
		game.update();
		game.render();
		SDL_Delay(1000 / 60);
	}
	game.clean();

	return 0;
}