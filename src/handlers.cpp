#include "handlers.hpp"
#include <iostream>

using namespace std;
SDL_Texture* AssetHandler::load_texture(string relative_file_path)
{
	if (!!strlen(this->asset_path.c_str()))
	{
		relative_file_path = this->asset_path + relative_file_path;
	}
    SDL_Texture* texture = IMG_LoadTexture(this->renderer, relative_file_path.c_str());
	if (!texture){
		std::cout << "error loading texture: " + relative_file_path << std::endl;
		std::cout << SDL_GetError() << std::endl;
	};
    return texture;
};

void AssetHandler::set_asset_path(std::string asset_path)
{
	this->asset_path = asset_path;
}
std::string AssetHandler::get_asset_path()
{
	return this->asset_path;
}
