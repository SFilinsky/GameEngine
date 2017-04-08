#include "Sprite.h"

bool Sprite::LoadSprite(const char* Name, SDL_Renderer* Renderer)
{
	try {
		SDL_Surface* pTempSurface = IMG_Load(Name);
		m_pCurrRenderer = Renderer;
		m_pTexture = SDL_CreateTextureFromSurface(m_pCurrRenderer, pTempSurface);
		SDL_FreeSurface(pTempSurface);
		SDL_QueryTexture(m_pTexture, NULL, NULL, &m_sourceRect.w, &m_sourceRect.h);
		m_sourceRect.x = 0;
		m_sourceRect.y = 0;
		return true;
	}
	catch(int e)
	{
		return false;
	}
	
}

bool Sprite::DrawSprite(int posX, int posY, float strchX, float strchY)
{
	try {
		if (m_pCurrRenderer != NULL)
		{
			m_destRect.x = posX;
			m_destRect.y = posY;
			m_destRect.w = (int)(strchX*m_sourceRect.w);
			m_destRect.h = (int)(strchY*m_sourceRect.h);

			SDL_RenderCopy(m_pCurrRenderer, m_pTexture, &m_sourceRect, &m_destRect);
			return true;
		}
	}
	catch(int e)
	{
		return false;

	}
}

bool Sprite::ClearSprite()
{
	try
	{
		SDL_DestroyTexture(m_pTexture);
		m_pCurrRenderer = nullptr;
		return true;
	}
	catch (int e)
	{
		return false;
	}
}