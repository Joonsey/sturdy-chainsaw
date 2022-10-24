#pragma once
#include <string>
#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>

class AssetHandler {
	public:
		AssetHandler(SDL_Renderer* renderer) {this->renderer = renderer;};
		~AssetHandler() {};
		SDL_Texture* load_texture(std::string);
		void set_asset_path(std::string);
		std::string get_asset_path();
	private:
		SDL_Renderer* renderer;
		std::string asset_path;
};
