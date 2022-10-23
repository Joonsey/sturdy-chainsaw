#include <SDL2/SDL.h>


struct O_color{
	int r;
	int g;
	int b;
	int a;
};

typedef struct O_color O_color;

class Object {
	public:
		Object(int x = 0, int y = 0, int w = 0, int h = 0);
		~Object() {};
		void render(SDL_Renderer* renderer);
		void set_color(int r, int g, int b, int a);
		int x;
		int y;
		int w;
		int h;
		O_color color;
	private:
		SDL_Rect as_rect();
};
