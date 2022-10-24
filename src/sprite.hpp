#pragma once
#include "object.hpp"


class Sprite : public Object {
	public:
		Sprite(SDL_Texture &texture, int x = 0, int y = 0, int w = 0, int h = 0);
		~Sprite();
		SDL_Texture* texture;
		void render(SDL_Renderer* renderer);
};

