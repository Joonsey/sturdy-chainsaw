#include "rect.hpp"

void Rect::render(SDL_Renderer* renderer)
{
	SDL_Rect rect = this->as_SDL_rect();
	SDL_SetRenderDrawColor(renderer, this->color.r, this->color.g, this->color.b, this->color.a);
	SDL_RenderFillRect(renderer, &rect);
}

void Rect::set_color(int r, int g, int b, int a)
{
	this->color.r = r;
	this->color.g = g;
	this->color.b = b;
	this->color.a = a;
}

Rect::Rect(int x, int y, int w, int h)
{
	this->x = x;
	this->y = y;
	this->w = w;
	this->h = h;
}
