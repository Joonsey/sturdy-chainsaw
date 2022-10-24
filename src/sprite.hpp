#pragma once
#include "object.hpp"
#include <SDL2/SDL_image.h>

class Sprite : public Object {
	public:
		Sprite(SDL_Texture*, int, int, int, int);
		~Sprite();
		SDL_Texture* texture;
		void render(SDL_Renderer* renderer);
};

