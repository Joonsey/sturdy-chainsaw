#include <SDL2/SDL.h>
#include <stdio.h>


#include "app.hpp"
#include "object.hpp"


int main (int argc, char** argv)
{
	App* app = new App();
	app->initSDL();
	Object* object = new Object(200);
	// object->x = 20; already in constructor
	// specs are optional, will default to 0
	object->y = 20;
	object->w = 20;
	object->h = 20;
	object->set_color(255, 0, 0, 0);

	while (1)
	{
		app->prepareScene();
		app->input();
		object->render(app->renderer);
		app->presentScene();


		SDL_Delay(16);
	}
    return EXIT_SUCCESS;
}
