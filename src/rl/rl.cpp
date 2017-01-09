#include "shared.h"
#include "render.h"

enum game_state {
	game_play,
	game_pause,
	game_exit,
};

const unsigned int TICKS_PER_SECOND =  25;
const unsigned int SKIP_TICKS = 1000/TICKS_PER_SECOND;
const unsigned int MAX_FRAMESKIP = 5;
const float MAX_ZOOM = 10.0f;

void
update(const Input &in, Camera *cam)
{
	if (in.is_key_down(SDLK_UP))
		cam->center.y-=15;
	if (in.is_key_down(SDLK_LEFT))
		cam->center.x-=15;
	if (in.is_key_down(SDLK_DOWN))
		cam->center.y+=15;
	if (in.is_key_down(SDLK_RIGHT))
		cam->center.x+=15;
}

#ifdef DEBUG
	void debug_update(Input *in)
	{
		if (in->was_key_pressed(SDLK_g))
			debug_info.show_grid = (debug_info.show_grid == false) ? true : false;
	}
#else
	void debug_update(Input *in) {}
#endif

int
main()
{
	init_sdl();

	SDL_Event e;
	game_state state = game_play;
	unsigned int num_updates = 0;
	unsigned int next_game_tick = 0;

	Input in;
	EntityID tile = make_entity();
	add_component<Static_Draw>(tile, "tile.png", (SDL_Rect){0,0,64,64});

	while (!(state == game_exit)) {
		switch (state) {
			case game_play: {
				num_updates = 0;
				while (next_game_tick < SDL_GetTicks() && num_updates < MAX_FRAMESKIP) {
					update(in);
					debug_update(&in);
					next_game_tick += SKIP_TICKS;
					num_updates++;
					//why++;
				}
				render();
				//get_fps(frameCount, loops, why, previousTime);
				break;
			}
		}
		while (SDL_PollEvent(&e) != 0) {
			switch (e.type) {
				case SDL_QUIT:
					state = game_exit;
					break;
				case SDL_KEYDOWN:
					in.key_pressed(e.key);
					break;
				case SDL_KEYUP:
					in.key_released(e.key);
					break;
				case SDL_MOUSEWHEEL:
					//cam.zoom += e.wheel.y/MAX_ZOOM;
					update_zoom(e.wheel.y);
					break;
			}
		}
	}
	render_quit();
	IMG_Quit();
	SDL_Quit();
	return 0;
}
