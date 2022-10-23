#include "app.hpp"

void App::prepareScene()
{
	SDL_SetRenderDrawColor(this->renderer, 120, 200, 130, 255);
	SDL_RenderClear(this->renderer);
}

void App::presentScene()
{
	SDL_RenderPresent(this->renderer);
}

void App::input()
{
	SDL_Event event;

	while (SDL_PollEvent(&event))
	{
		switch (event.type)
		{
			case SDL_QUIT:
				exit(0);
				break;

			default:
				break;
		}
	}
}

void App::initSDL()
{
	int rendererFlags, windowFlags;

	rendererFlags = SDL_RENDERER_ACCELERATED;

	windowFlags = 0;

	if (SDL_Init(SDL_INIT_VIDEO) < 0)
	{
		printf("Couldn't initialize SDL: %s\n", SDL_GetError());
		exit(1);
	}

	this->window = SDL_CreateWindow("yey", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, SCREEN_WIDTH, SCREEN_HEIGHT, windowFlags);

	if (!this->window)
	{
		printf("Failed to open %d x %d window: %s\n", SCREEN_WIDTH, SCREEN_HEIGHT, SDL_GetError());
		exit(1);
	}

	SDL_SetHint(SDL_HINT_RENDER_SCALE_QUALITY, "linear");

	this->renderer = SDL_CreateRenderer(this->window, -1, rendererFlags);

	if (!this->renderer)
	{
		printf("Failed to create renderer: %s\n", SDL_GetError());
		exit(1);
	}
}
