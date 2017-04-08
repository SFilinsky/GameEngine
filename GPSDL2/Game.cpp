#include "Game.h"


Game::Game()
{

}


Game::~Game()
{

}


//note Game initialization. Returns true and starts main game cycle on success
bool Game::init(const char* title, int xpos, int ypos, int height, int width, int flags)
{

	//Initializing lib
	
	if (SDL_Init(SDL_INIT_EVERYTHING) >= 0)
	{

		SDL_LogSetAllPriority(SDL_LOG_PRIORITY_WARN);

		IMG_Init(ImgFlags);

		//Creating window
		m_pWindow = SDL_CreateWindow(title, xpos, ypos, height, width, flags);

		//Creating renderer if window created
		if (m_pWindow != 0)
		{

			//Creating renderer
			m_pRenderer = SDL_CreateRenderer(m_pWindow, -1, SDL_RENDERER_TARGETTEXTURE);


			if (m_pRenderer != 0)
			{
				Image1.LoadSprite("D:/Projects/OpenGL/GPSDL2/Images/PlayerSuit.png",m_pRenderer);
				Image2.LoadSprite("D:/Projects/OpenGL/GPSDL2/Images/PlayerSuit.png", m_pRenderer);
				
				
			}
			else
			{
				return false;
			}
		}
		else
		{
			return false;
		}
	}
	else
	{
		return false;
	}

	m_bRunning = true;

	return true;
}


//note Cleaning game resourses and Quiting SDL.
void Game::clean()
{
	SDL_DestroyWindow(m_pWindow);
	SDL_DestroyRenderer(m_pRenderer);
	SDL_Quit();
}


//note Main rendering proceudure. Its called in main game cycle
void Game::render()
{
	SDL_RenderClear(m_pRenderer);
	Image1.DrawSprite(100,100,1,1);
	Image2.DrawSprite(200,200,1,1);
	SDL_RenderPresent(m_pRenderer);
}


//note Main event handler. Its called in main game cycle
void Game::handleEvents()
{
	SDL_Event event;
	if (SDL_PollEvent(&event))
	{
		switch (event.type)
		{
		case SDL_QUIT:
			m_bRunning = false;
			break;

		default:
			break;
		}
	}
}



void Game::update()
{

}