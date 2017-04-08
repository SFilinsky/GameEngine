#include <SDL.h>
#include <SDL_image.h>
#include "Game.h"


Game* g_Game = 0;

//Game Settings
int startWindowW = 640;
int startWindowH = 480;
int startWindowMode = 0;


int main(int argc, char* argv[])
{
	g_Game =new Game();

	g_Game->init("GameEngine", 100, 100, startWindowW, startWindowH, startWindowMode);

	//Main game cycle
	while (g_Game->Game::running())
	{
		g_Game->Game::handleEvents();
		g_Game->Game::update();
		g_Game->Game::render();
	}
	g_Game->Game::clean();

	return 0;
}