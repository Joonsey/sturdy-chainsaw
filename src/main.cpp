#include <SDL2/SDL.h>
#include <stdio.h>

#include "app.hpp"



class Object{
	public:
		Object();
		~Object();
		int x;
		int y;
		int sx;
		int sy;
};



int main (int argc, char** argv)
{
	App* app = new App();
	app->initSDL();

	while (1)
	{
		app->prepareScene();
		app->input();
		app->presentScene();

		SDL_Delay(16);
	}
    return EXIT_SUCCESS;
}
