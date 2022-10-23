#include <SDL2/SDL.h>
#include "defs.hpp"

class App{
	public:
		App() {};
		~App() {};
		void initSDL();
		void input();
		void prepareScene();
		void presentScene();
		SDL_Renderer *renderer;
		SDL_Window *window;
};
