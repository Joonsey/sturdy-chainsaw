#pragma once
#include <SDL2/SDL.h>
#include "defs.hpp"
#include <string>

class App{
	public:
		App(std::string);
		~App() {};
		void initSDL();
		void input();
		void prepareScene();
		void presentScene();
		SDL_Renderer *renderer;
		SDL_Window *window;
	private:
		std::string title;
};
