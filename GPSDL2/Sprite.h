#pragma once
#include <SDL.h>
#include <SDL_Image.h>

class Sprite
{
public:
	bool LoadSprite(const char* Name, SDL_Renderer* Renderer);
	bool DrawSprite(int posX, int posY, float strchX, float strchY);
	bool ClearSprite();
	

private:
	SDL_Rect m_sourceRect; //Sprite size rectangle
	SDL_Rect m_destRect; //Sprite screen position and stretching rectangle
	SDL_Texture* m_pTexture;
	SDL_Renderer* m_pCurrRenderer;
};