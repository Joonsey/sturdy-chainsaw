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
	Sprite * sprite = new Sprite(*texture, 255, 1, 25, 25);
	tester->is_equal(sprite->x == 255, "expecting sprite x == 255, got "+std::to_string(sprite->x));
	tester->is_equal(sprite->y == 1, "expecting sprite y == 0, got "+std::to_string(sprite->y));
	tester->is_equal(sprite->w == 25, "expecting sprite w == 25, got "+std::to_string(sprite->w));
}

int main()
{
	//App_init_test();
	Object_init_test();
	Rect_color_behaviour();
	Rect_inherit_test();
	Sprite_init_test();
	tester->conclude();
}

