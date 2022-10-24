#include "sprite.hpp"
#include <iostream>

Sprite::Sprite(SDL_Texture *texture, int x, int y, int w, int h)
{
	this->texture = texture;
	this->x = x;
	this->y = y;
	this->w = w;
	this->h = h;
};

Sprite::~Sprite()
{

};

void Sprite::render(SDL_Renderer* renderer)
{
	SDL_Rect rect = this->as_SDL_rect();
	SDL_RenderCopy(renderer, this->texture, NULL, &rect);
};
