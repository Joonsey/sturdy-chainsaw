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
	//std::cout << this->particles.size() << std::endl;
	//the size of the vector behaves as expected;
	//shrinks dynamically upon cleanup
	int i = 0;
	for (Particle_Rect* particle : this->particles)
	{
		particle->x -= rand() % 2;
		particle->y += rand() % 2;

		// remove particle from memory if it outside the bounds of the screen

		// this is bugged and the particles need to be compensated for their width and height
		// todo: fix this
		if (particle->x < 0 | particle->y < 0 | particle->y > SCREEN_HEIGHT | particle->x > SCREEN_WIDTH)
		{
			this->particles.erase(this->particles.begin()+i);
			//std::cout << "free-ing particle" << std::endl;
			//particle gets freed if conditions are met
		}
		i++;
	}
}

void ParticleHandler::render(SDL_Renderer* renderer)
{
	for (Particle_Rect* particle : this->particles)
	{
		particle->render(renderer);
	}
}
