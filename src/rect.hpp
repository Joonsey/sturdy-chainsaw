#pragma once
#include <SDL2/SDL.h>
#include "object.hpp"

class Rect : public Object {
	public:
		Rect(int = 0, int = 0, int = 0, int = 0);
		~Rect() {};
		void set_color(int, int, int, int);
		void render(SDL_Renderer*);
		O_color color;
};

