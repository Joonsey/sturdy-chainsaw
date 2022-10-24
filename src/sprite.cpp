#include "sprite.hpp"
#include <SDL2/SDL_image.h>
#include <iostream>

Sprite::Sprite(SDL_Texture &texture, int x, int y, int w, int h)
{
	this->texture = &texture;
	this->x = x;
	this->y = y;
	this->w = w;
	this->h = h;
};

Sprite::~Sprite()
{

};

SDL_Texture* AssetHandler::load_texture(string relative_file_path)
{
	SDL_Texture *texture = NULL;
	if (!!strlen(this->asset_path.c_str()))
	{
		relative_file_path = this->asset_path + relative_file_path;
	}
    SDL_Surface *surface = IMG_Load(relative_file_path.c_str());
    if (surface) {
        texture = SDL_CreateTextureFromSurface(renderer, surface);
        SDL_FreeSurface(surface);
    }
	else{
		std::cout << "error loading texture: " + relative_file_path << std::endl;
	};
    return texture;
};

void Sprite::render(SDL_Renderer* renderer)
{
	SDL_Rect rect = this->as_SDL_rect();
	SDL_RenderCopy(renderer, this->texture, NULL, &rect);
};
