#ifndef __SHARED_H__
#define __SHARED_H__

#include <stdio.h>
#include <stdlib.h>
#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>

struct Debug_Info {
	bool show_grid = false;
};

extern Debug_Info debug_info;

struct Vector2 {
	Vector2(int nx, int ny) : x(nx), y(ny) {}
	Vector2(const Vector2 &v) : x(v.x), y(v.y) {}
	Vector2() : x(0), y(0) {}
	int x, y;
};

struct Camera {
	Camera(int x, int y) : center(x, y) {}
	Camera(Vector2 c) : center(c) {}
	Camera() : center(0, 0) {}
	Vector2 center;
	float zoom = 1.0f;
};

class Input {
public:
	Input() : keys{false}, keys_toggle{false} {}

	void key_pressed(const SDL_KeyboardEvent&);
	void key_released(const SDL_KeyboardEvent&);
	bool is_key_down(const SDL_Keycode) const;
	bool was_key_pressed(const SDL_Keycode);
private:
	bool keys[256];
	bool keys_toggle[256];
};


template <typename... Args>
void log_err(Args... args) {
	fprintf(stderr, "Error: ");
	fprintf(stderr, args...);
	fprintf(stderr, "\n");
}

template <typename... Args>
void abort(Args... args) {
	log_err(args...);
	fprintf(stderr, "Aborting...\n");
	exit(1);
}

using EntityID = unsigned long long;

#endif