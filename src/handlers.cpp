#include "handlers.hpp"
#include <iostream>

SDL_Texture* AssetHandler::load_texture(std::string relative_file_path)
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



Particle_Rect * ParticleHandler::spawn_particle(){
	return new Particle_Rect(rand() % 100 + 400, rand() % 100, 24, 24);
}

void ParticleHandler::add_particle(Particle_Rect * particle)
{
	this->particles.push_back(particle);
}

void ParticleHandler::update()
{
	for (Particle_Rect* particle : this->particles)
	{
		particle->x -= rand() % 2;
		particle->y += rand() % 2;
	}
}

void ParticleHandler::render(SDL_Renderer* renderer)
{
	for (Particle_Rect* particle : this->particles)
	{
		particle->render(renderer);
	}
}
