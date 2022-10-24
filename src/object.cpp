#include "object.hpp"


SDL_Rect Object::as_SDL_rect()
{
	SDL_Rect rect;
	rect.x = this->x;
	rect.y = this->y;
	rect.w = this->w;
	rect.h = this->h;

	return rect;
}


Object::Object(int x, int y, int w, int h)
{
	this->x = x;
	this->y = y;
	this->w = w;
	this->h = h;
}
