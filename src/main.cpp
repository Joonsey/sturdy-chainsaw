#include <SDL2/SDL.h>
#include <iostream>

#include "app.hpp"
#include "object.hpp"
#include "sprite.hpp"
#include "rect.hpp"
#include "handlers.hpp"

int main (int argc, char** argv)
{
	App* app = new App();
	app->initSDL();

	AssetHandler * asset_handler = new AssetHandler(app->renderer);
	asset_handler->set_asset_path("./assets/");

	SDL_Texture* image = asset_handler->load_texture("images/image.png");
	Sprite * sprite = new Sprite(image, 100, 20, 20, 20);

	Rect* rect = new Rect(200, 200, 20, 20);
	rect->set_color(255, 230, 0, 0);


	//colision test
	Rect* red_rect = new Rect(20, 0, 30, 29);
	red_rect->set_color(255,0,0,255);
	Rect* green_rect = new Rect(15, 10, 30, 30);
	green_rect->set_color(0,255,0,255);
	while (1)
	{
		app->prepareScene();
		app->input();
		red_rect->render(app->renderer);
		green_rect->render(app->renderer);
		rect->render(app->renderer);
		sprite->render(app->renderer);
		app->presentScene();


		SDL_Delay(16);
	}
    return EXIT_SUCCESS;
}
