#pragma once
#include "object.hpp"
#include "string"

using namespace std;

class AssetHandler {
	public:
		AssetHandler(SDL_Renderer* renderer) {this->renderer = renderer;};
		~AssetHandler() {};
		SDL_Texture* load_texture(string relative_file_path );
		string asset_path;
	private:
		SDL_Renderer* renderer;
};

class Sprite : public Object {
	public:
		Sprite(SDL_Texture &texture, int x = 0, int y = 0, int w = 0, int h = 0);
		~Sprite();
		SDL_Texture* texture;
		void render(SDL_Renderer* renderer);
};

