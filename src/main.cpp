#include <SDL2/SDL.h>
#include <iostream>

#include "app.hpp"
#include "particle.hpp"
#include "object.hpp"
#include "sprite.hpp"
#include "rect.hpp"
#include "handlers.hpp"
#include "config.hpp"

int main (int argc, char** argv)
{
	//checking args
	char* current_arg;
	bool no_config = false;
	for( int x= 0; x < argc; x++ )
	{
		current_arg = argv[x];
		check_config(current_arg, no_config);
	};

	if (!no_config)
	{
		cout << "loading configs.." << endl;
		ConfigHandler * configHandler = new ConfigHandler();
		configHandler->parse_settings_from_file("src/config");
	}

	App* app = new App("yoo");
	app->initSDL();

	AssetHandler * asset_handler = new AssetHandler(app->renderer);
	asset_handler->set_asset_path("./assets/");

	SDL_Texture* image = asset_handler->load_texture("images/image.png");
	Sprite * sprite = new Sprite(image, 100, 20, 20, 20);

	Rect* rect = new Rect(200, 200, 20, 20);
	rect->set_color(255, 230, 0, 0);

	Particle_Rect * particle = new Particle_Rect(120, 120, 24,24);
	particle->set_color(123, 124, 234, 255);

	//colision test
	Rect* red_rect = new Rect(20, 0, 30, 29);
	red_rect->set_color(255,0,0,255);
	Rect* green_rect = new Rect(15, 10, 30, 30);
	green_rect->set_color(0,255,0,255);

	//particle handler
	ParticleHandler* particleHandler = new ParticleHandler();
	particleHandler->add_particle(particle);
	int interval = 100;
	while (1)
	{
		interval --;
		app->prepareScene();
		app->input();

		// todo: make assetshandler or similar render and manager
		// all assets / objects
		red_rect->render(app->renderer);
		green_rect->render(app->renderer);
		rect->render(app->renderer);
		sprite->render(app->renderer);

		particleHandler->update();
		particleHandler->render(app->renderer);
		app->presentScene();

		if (interval < 0) {
			particleHandler->add_particle(particleHandler->spawn_particle());
			interval = 100;
		}


		SDL_Delay(16);
	}
    return EXIT_SUCCESS;
}
