// screen.h
//
#include <SDL.h>
#include <string>

#include "color.h"

#pragma once

namespace vmonitor {
class Screen {
private:
	SDL_Window* m_window;
	SDL_Renderer* m_renderer;
	SDL_Texture* m_texture;
	Uint32* m_buffer;
private:
	void close();
	bool init();
	void print_err_msg(std::string) const;
	void set_pixel(const int x, const int y, const Color color) const;
protected:
	// colors a square of pixels starting at x
	// having diagonal of d squared
	void set_pixel_sq(const int x, 
			const int y, 
			const int d, 
			const Color color) const;
public:
	const static int SCREEN_WIDTH = 600;
	const static int SCREEN_HEIGHT = 600;
public:
	Screen();
	void render() const;
	bool process_events() const;
};
}
