#include <SDL2/SDL.h>
#include <stdio.h>

#include "app.hpp"
#include "object.hpp"
#include "sprite.hpp"
#include "rect.hpp"

int main (int argc, char** argv)
{
	App* app = new App();
	app->initSDL();
	Rect* rect = new Rect(200);
	rect->y = 20;
	rect->w = 20;
	rect->h = 20;
	rect->set_color(255, 0, 0, 0);

	while (1)
	{
		app->prepareScene();
		app->input();
		rect->render(app->renderer);
		app->presentScene();


		SDL_Delay(16);
	}
    return EXIT_SUCCESS;
}
