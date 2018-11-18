#pragma once

#include "SDL.h"
#include <SDL_image.h>
#include <iostream>
#include "TextureManager.h"
#include "Player.h"
#include "Enemy.h"
#include <vector>


class Game
{
public:
	bool init(const char* title, int xpos, int ypos, int width, int height, int flags);

	void render();
	void update();
	void handleEvent();
	void clean();
	bool running() { return m_bRunning; }

	SDL_Renderer* getRenderer() const { return m_pRenderer; }

	static Game* Instance()
	{
		if (s_pInstance == 0)
		{
			s_pInstance = new Game();
			return s_pInstance;
		}
		return s_pInstance;
	}


private:
	Game() {}
	static Game* s_pInstance;

	//GameObject * m_go;
	//GameObject* m_player;
	//GameObject* m_enemy;

	SDL_Window * m_pWindow;
	SDL_Renderer* m_pRenderer;
	bool m_bRunning;

	std::vector<GameObject*> m_gameObjects;
};
typedef Game TheGame;