#include <string>
#include "shared.h"
#include "render.h"

static SDL_Renderer *g_renderer;
static SDL_Window *g_window;
static Camera g_camera;

const int TILE_SIZE = 32;

std::map<EntityID, std::unique_ptr<Static_Draw>> Static_Draw::all;

void init_sdl()
{
	int winflags = (SDL_WINDOW_SHOWN);
	int imgflags = (IMG_INIT_PNG | IMG_INIT_JPG);
	int renderflags = (SDL_RENDERER_ACCELERATED);

	if(SDL_Init(SDL_INIT_VIDEO | SDL_INIT_EVENTS) < 0)
		abort("SDL could not initialize video! SDL Error: %s\n", SDL_GetError());
	if (!(g_window = SDL_CreateWindow("cge", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, 800, 600, winflags)))
		abort("SDL could not create a window! SDL Error: %s\n", SDL_GetError());
	if (!(g_renderer = SDL_CreateRenderer(g_window, -1, renderflags)))
		abort("SDL could not create renderer! SDL Error: %s\n", SDL_GetError());
	//initialize PNG loading
	if (!(IMG_Init(imgflags) & imgflags))
		abort("SDL_image could not initialize! SDL_image Error: %s\n", IMG_GetError());
}

Texture::Texture(const std::string &file_path)
{
	load_texture(file_path);
}

Texture::Texture()
{
	tex = nullptr;
}

Texture::~Texture()
{
	if (tex)
		SDL_DestroyTexture(tex);
}

bool Texture::load_texture(const std::string &file_path)
{
	SDL_Surface *surf = IMG_Load(file_path.c_str());
	if (!surf) {
		//just abort for now
		abort("Failed to load image %s!", file_path);
		return false;
	}
	tex = SDL_CreateTextureFromSurface(g_renderer, surf);
	if (!tex) {
		//just abort for now
		abort("Failed to create texture %s!", file_path);
		return false;
	}
	SDL_FreeSurface(surf);
	return true;
}

#ifdef DEBUG
	void show_grid(const Camera &cam)
	{
		if (debug_info.show_grid) {
			SDL_SetRenderDrawColor(g_renderer, 255, 0, 0, 255);
			int camx = cam.center.x;
			int camy = cam.center.y;
			float z = cam.zoom*TILE_SIZE;
			for (int i = 0; i < 1000; ++i) {
				SDL_RenderDrawLine(g_renderer, i*z-camx, 0-camy, i*z-camx, 1000-camy);
				SDL_RenderDrawLine(g_renderer, 0-camx, i*z-camy, 1000-camx, i*z-camy);
			}
		}
	}
	
	void debug_render(const Camera &cam)
	{
		show_grid(cam);
	}
#else
	void debug_render(const Camera &cam) {}
#endif

void render(const Camera &cam)
{				
	SDL_SetRenderDrawColor(g_renderer, 0x00, 0x00, 0x00, 0x00);
	SDL_RenderClear(g_renderer);
	for (const auto &x : Static_Draw::all) {
		SDL_RenderCopy(g_renderer, x.second->texture.tex, NULL, &x.second->screen_dest);
	}
	debug_render(cam);
	SDL_RenderPresent(g_renderer);
}

void render_quit()
{
	SDL_DestroyWindow(g_window);
	SDL_DestroyRenderer(g_renderer);
}

EntityID make_entity()
{
	static EntityID count = 0;
	return count++;
}

void update_zoom(const float zoom)
{
	for (auto &r : Static_Draw::all) {
		r.second->screen_dest.x = r.second->dest.x * zoom;
		r.second->screen_dest.y = r.second->dest.y * zoom;
		r.second->screen_dest.w = r.second->dest.w * zoom;
		r.second->screen_dest.h = r.second->dest.h * zoom;
	}
	debug_update_zoom(zoom);
}

void update_pos(