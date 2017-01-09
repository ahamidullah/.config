#ifndef __RENDER_H__
#define __RENDER_H__

#include <map>
#include <memory>

struct Texture {
	Texture(const std::string &);
	Texture();
	~Texture();
	bool load_texture(const std::string &);

	SDL_Texture *tex;
	Vector2 dimensions;
};

struct Static_Draw {
	Static_Draw(const std::string &tex_path, const SDL_Rect &d) : texture(tex_path), dest{d}, screen_dest{d} {}
	Texture texture;
	SDL_Rect dest;
	SDL_Rect screen_dest;
	static std::map<EntityID, std::unique_ptr<Static_Draw>> all;
};

template <typename T, typename... Args>
void add_component(EntityID id, Args... args)
{
	T::all[id] = std::make_unique<T>(args...);
}

EntityID make_entity();
void init_sdl();
void render(const Camera &);
void render_quit();
void update_zoom(const float);

#endif