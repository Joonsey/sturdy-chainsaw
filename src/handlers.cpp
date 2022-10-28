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

	// only works due to being in ascending order
	std::vector<int> indexes_to_remove;
	for (int i = 0; i < this->particles.size(); i++)
	{
		Particle_Rect* particle = this->particles[i];
		particle->x -= rand() % 5+2;
		particle->y += rand() % 5+2;

		if (particle->x + particle->w < 0 | particle->y + particle->h < 0 | particle->y > SCREEN_HEIGHT | particle->x > SCREEN_WIDTH)
		{
			indexes_to_remove.push_back(i);
		}
	}
	for (int i = 0; i < indexes_to_remove.size(); i++)
	{
		int index = indexes_to_remove[i];
		this->particles.erase(this->particles.begin()+ index-i);
	}
}

void ParticleHandler::render(SDL_Renderer* renderer)
{
	for (Particle_Rect* particle : this->particles)
	{
		particle->render(renderer);
	}
}
