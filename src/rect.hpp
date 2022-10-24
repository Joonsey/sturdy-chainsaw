#pragma once
#include <SDL2/SDL.h>
#include "object.hpp"

class Rect : public Object {
	public:
		Rect(int x = 0, int y = 0, int w = 0, int h = 0);
		~Rect() {};
		void set_color(int r, int g, int b, int a);
		void render(SDL_Renderer* renderer);
		O_color color;
};

