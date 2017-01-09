#include "shared.h"

// key is being pressed
void Input::key_pressed(const SDL_KeyboardEvent &e)
{
	keys[e.keysym.scancode] = true;
	if (!e.repeat)
		keys_toggle[e.keysym.scancode] = true;
}

// key was just released
void Input::key_released(const SDL_KeyboardEvent &e)
{
	keys[e.keysym.scancode] = false;
	keys_toggle[e.keysym.scancode] = false;
}

// is the key currently pressed
bool Input::is_key_down(const SDL_Keycode k) const
{
	return keys[SDL_GetScancodeFromKey(k)];
}

// has the key moved from released to pressed? untoggle key
bool Input::was_key_pressed(const SDL_Keycode k)
{
	const SDL_Scancode sc = SDL_GetScancodeFromKey(k);
	const bool t = keys_toggle[sc];
	keys_toggle[sc] = false;
	return t;
}

Debug_Info debug_info;