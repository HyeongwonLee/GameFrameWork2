#pragma once
#include "SDL.h"


class InputHandler
{
public:
	static InputHandler* Instance()
	{
		if (s_pInstance == 0) {
			s_pInstance = new InputHandler();
		}
		return s_pInstance;
	}
	void update();
	void clean();  // ����̽� ���� �ʱ�ȭ�� �κ��� clear 
	bool isKeyDown(SDL_Scancode key);
private:
	InputHandler();
	~InputHandler() {}
	const Uint8* m_keystates;
	static InputHandler* s_pInstance;
};


typedef InputHandler TheInputHandler;