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
	bool init();
	void close();

	// graphics
	void set_pixel(const int x, const int y, const Color color) const;

	// errors
	void print_err_msg(std::string) const;
protected:
	void render() const;
	// colors a square of pixels starting at x
	// having diagonal of d squared
	void set_pixel_sq(const int x, 
			const int y, 
			const int d, 
			const Color color) const;

	// virtuals
	virtual void on_mouse_down() const = 0;
	// virtual void on_mouse_move() const;
public:
	const static int SCREEN_WIDTH = 600;
	const static int SCREEN_HEIGHT = 600;
public:
	Screen();
	bool process_events() const;
};
}
