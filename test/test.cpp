#include "result.hpp"
#include "tester.hpp"

#include "../src/app.hpp"
#include "../src/defs.hpp"
#include "../src/object.hpp"

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
	tester->is_equal(!object->x, "expecting object x == 0 when not changed got: "+ std::to_string(object->x));
}

void Object_color_behaviour()
{
	Object * object = new Object();
	object->set_color(20, 30, 45, 255);
	tester->is_equal(object->color.a == 255, "expecting color setter to set color");
	tester->is_equal(object->color.r == 20, "expecting color setter to set color");
	tester->is_equal(object->color.b == 45, "expecting color setter to set color");
}
int main()
{
	//App_init_test();
	Object_init_test();
	Object_color_behaviour();
	tester->conclude();
}
