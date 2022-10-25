#pragma once
#include <string>
#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <stdlib.h>
#include <vector>


#include "particle.hpp"

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

class ParticleHandler {
	public:
		ParticleHandler() {};
		~ParticleHandler() {};
		std::vector<Particle_Rect*> particles;
		Particle_Rect* spawn_particle();
		void add_particle(Particle_Rect*);
		void update();
		void render(SDL_Renderer*);
	private:
		void randomly_move_particle(Particle_Rect*);
};

