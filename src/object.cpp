#include "object.hpp"

void Object::render(SDL_Renderer* renderer)
{
	SDL_Rect rect = this->as_rect();
	SDL_SetRenderDrawColor(renderer, this->color.r, this->color.g, this->color.b, this->color.a);
	SDL_RenderFillRect(renderer, &rect);
}

SDL_Rect Object::as_rect()
{
	SDL_Rect rect;
	rect.x = this->x;
	rect.y = this->y;
	rect.w = this->w;
	rect.h = this->h;

	return rect;
}

void Object::set_color(int r, int g, int b, int a)
{
	this->color.r = r;
	this->color.g = g;
	this->color.b = b;
	this->color.a = a;
}

Object::Object(int x, int y, int w, int h)
{
	this->x = x;
	this->y = y;
	this->w = w;
	this->h = h;
}
