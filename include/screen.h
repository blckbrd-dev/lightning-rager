// screen.h
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
	mutable Uint32* m_buffer;
private:
	// graphics
	void set_pixel(const int x, const int y, const Color color) const;

	// errors
	void print_err_msg(std::string) const;
protected:
	mutable bool m_drawing;
	bool init_fail;
protected:

	bool _init(int, int);

	void render() const;
	// colors a square of pixels starting at x
	// having diagonal of d squared
	void set_pixel_sq(const int x, 
			const int y, 
			const int d, 
			const Color color) const;

	// virtuals
	virtual void on_mouse_down()	const	= 0;
	virtual void on_mouse_up()		const = 0;
	virtual void on_mouse_move()	const	= 0;
	virtual void on_mouse_drag()	const	= 0;
public:
	int SCREEN_WIDTH;
	int SCREEN_HEIGHT;
public:
	Screen();
	bool process_events() const;
	void close() const;
};
}
