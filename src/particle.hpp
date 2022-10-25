#pragma once
#include "object.hpp"
#include "rect.hpp"

class Particle
{
	public:
		int velocity;
		float reduce_time_to_live(float);
		void set_on_death_callback(void*());
	protected:
		float lifetime;
};

class Particle_Rect : public Particle, public Rect
{
	public:
		Particle_Rect(int x = 0, int y = 0, int w = 0, int h = 0);
		~Particle_Rect() {};
};

