#include "object.hpp"


SDL_Rect Object::as_SDL_rect()
{
	SDL_Rect rect;
	rect.x = this->x;
	rect.y = this->y;
	rect.w = this->w;
	rect.h = this->h;

	return rect;
}


Object::Object(int x, int y, int w, int h)
{
	this->x = x;
	this->y = y;
	this->w = w;
	this->h = h;
}

bool Object::objects_colide(Object* first_object, Object* second_object)
{

	bool coliding = false;
	if (
			first_object->x < second_object->x + second_object->w &
			first_object->x + first_object->w > second_object->x &
			first_object->y < second_object->y + second_object->h &
			first_object->y + first_object->h > second_object->y
		)
	{
		coliding = true;
	}

	return coliding;
}

bool Object::coliding_with_other_object(Object * other_object)
{
	return objects_colide(this, other_object);
}

