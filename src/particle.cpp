#include "particle.hpp"
#include <iostream>

Particle_Rect::Particle_Rect(int x, int y, int w, int h)
{
	this->x = x;
	this->y = y;
	this->w = w;
	this->h = h;
}

float Particle::reduce_time_to_live(float reduction)
{
	// todo: free particle upon death
	// todo: at some point define lifetime
	return this->lifetime -= reduction;
}

void Particle::set_on_death_callback(void*())
{
	std::cout << "not yet implemented" << std::endl;
}

