#include "result.hpp"
#include "tester.hpp"

#include "../src/app.hpp"
#include "../src/defs.hpp"
#include "../src/object.hpp"
#include "../src/sprite.hpp"
#include "../src/rect.hpp"

Tester * tester = new Tester();

void App_init_test()
{
	// CANT RUN THIS IN CI AS RUNNERS CANT PRODUCE A RENDERER
	App * app = new App();
	app->initSDL();
	tester->is_equal(!!app, "expecting app to exist");
	tester->is_equal(!!app->renderer, "expecting app renderer to exist");
	tester->is_equal(!!app->window, "expecting app window to exist");
}

void Object_init_test()
{
	Object * object = new Object();
	tester->is_equal(!!object, "expecting object to exist");
	tester->is_equal(!object->x, "expecting object x == 0, got: "+ std::to_string(object->x));
}

void Rect_color_behaviour()
{
	Rect * rect = new Rect();
	rect->set_color(20, 30, 45, 255);
	tester->is_equal(rect->color.a == 255, "expecting color setter to set color");
	tester->is_equal(rect->color.r == 20, "expecting color setter to set color");
	tester->is_equal(rect->color.b == 45, "expecting color setter to set color");
}

void Rect_inherit_test()
{
	Rect * rect = new Rect(255, 1, 25, 25);
	tester->is_equal(rect->x == 255, "expecting rect x == 255, got "+std::to_string(rect->x));
	tester->is_equal(rect->y == 1, "expecting rect y == 0, got "+std::to_string(rect->y));
	tester->is_equal(rect->w == 25, "expecting rect w == 25, got "+std::to_string(rect->w));
}

void Sprite_init_test()
{
	SDL_Texture *texture;
	Sprite * sprite = new Sprite(texture, 255, 1, 25, 25);
	tester->is_equal(sprite->x == 255, "expecting sprite x == 255, got "+std::to_string(sprite->x));
	tester->is_equal(sprite->y == 1, "expecting sprite y == 0, got "+std::to_string(sprite->y));
	tester->is_equal(sprite->w == 25, "expecting sprite w == 25, got "+std::to_string(sprite->w));
}

void Rect_colision_test()
{
	Rect * object = new Rect(0, 0, 30, 30);
	Rect * second_object = new Rect(20, 0, 30, 29);
	tester->is_equal(object->coliding_with_other_object(second_object), "expecting sprites to collide");
	tester->is_equal(Object::objects_colide(object, second_object), "expecting rects to collide using static method");
	tester->is_equal(!object->coliding_with_other_object(new Object(40, 40, 30, 30)), "expecting to NOT collide with rect");
	tester->is_equal(!object->coliding_with_other_object(new Object(-40, 0, 30, 30)), "expecting to NOT collide with rect");
	tester->is_equal(second_object->coliding_with_other_object(new Object(15, 10, 30, 30)), "expecting to collide with rect");
}

void Sprite_colision_test()
{
	SDL_Texture* texture;
	Sprite * object = new Sprite(texture, 0, 0, 30, 30);
	Sprite * second_object = new Sprite(texture, 20, 0, 30, 29);
	tester->is_equal(object->coliding_with_other_object(second_object), "expecting sprites to collide");
	tester->is_equal(Object::objects_colide(object, second_object), "expecting sprites to collide using static method");
	tester->is_equal(!object->coliding_with_other_object(new Object(40, 40, 30, 30)), "expecting to NOT collide with sprite");
	tester->is_equal(!object->coliding_with_other_object(new Object(-40, 0, 30, 30)), "expecting to NOT collide with sprite");
	tester->is_equal(second_object->coliding_with_other_object(new Object(15, 10, 30, 30)), "expecting to collide with sprite");
}

void Object_colision_test()
{
	Object * object = new Object(0, 0, 30, 30);
	Object * second_object = new Object(20, 0, 30, 29);
	tester->is_equal(object->coliding_with_other_object(second_object), "expecting objects to collide");
	tester->is_equal(Object::objects_colide(object, second_object), "expecting objects to collide using static method");
	tester->is_equal(!object->coliding_with_other_object(new Object(40, 40, 30, 30)), "expecting to NOT collide with object");
	tester->is_equal(!object->coliding_with_other_object(new Object(-40, 0, 30, 30)), "expecting to NOT collide with object");
	tester->is_equal(second_object->coliding_with_other_object(new Object(15, 10, 30, 30)), "expecting to collide with object");
}


int main()
{
	//App_init_test();

	Rect_color_behaviour();

	// init tests
	Object_init_test();
	Rect_inherit_test();
	Sprite_init_test();

	// colision tests
	Object_colision_test();
	Rect_colision_test();
	Sprite_colision_test();

	//concluding test
	tester->conclude();
}

