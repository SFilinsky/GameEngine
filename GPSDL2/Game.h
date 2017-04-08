#pragma once
#include <SDL.h>
#include <SDL_Image.h>
#include <IOStream>
#include "Sprite.h"

#ifndef __Game__
#define __Game__

class Game
{
public:
	Game();
	~Game();

	//note Initialize Game. Returns false on fail
	bool init(const char* title, int xpos, int ypos, int height, int width, int flags);
	void render();
	void update();
	void handleEvents();
	void clean();

	bool running() { return m_bRunning;  }

private:

	SDL_Window* m_pWindow;
	SDL_Renderer* m_pRenderer;

	SDL_Texture* m_pTexture;
	SDL_Rect m_sourceRectangle;
	SDL_Rect m_destinationRectangle;
	Sprite Image1;
	Sprite Image2;

	//note Game Processing Indicator 
	bool m_bRunning;
	
	int ImgFlags = IMG_INIT_PNG;
};

#endif /* defined(__Game__); */


