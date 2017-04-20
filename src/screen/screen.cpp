#include <iostream>
#include "screen.h"

// usings
using std::cout;
using std::endl;

namespace vmonitor {
// macros
// delete and set null
#define del(x) { delete x; x = NULL; }
#define del_arr(x) { delete [] x; x = NULL; }

	Screen::Screen():
		m_window(NULL),
		m_renderer(NULL),
		m_texture(NULL),
		m_buffer(NULL) {
			// constructor body
			if(!init())
				close();
		}

	bool Screen::init() {
		// SDL init
		if(SDL_Init(SDL_INIT_VIDEO) < 0) {
			print_err_msg("SDL init failed.");
			return false;
		}

		// create window
		m_window = 
			SDL_CreateWindow("Particle Fire Explosion", 
					SDL_WINDOWPOS_UNDEFINED, 
					SDL_WINDOWPOS_UNDEFINED, 
					SCREEN_WIDTH,
					SCREEN_HEIGHT,
					SDL_WINDOW_SHOWN);

		// window null error
		if(m_window == NULL) {
			print_err_msg("SDL Window init failed.");
			return false;
		}

		// syncing renderer
		m_renderer = SDL_CreateRenderer(m_window, 
				-1, 
				SDL_RENDERER_PRESENTVSYNC);

		// check for errors
		if(m_renderer == NULL) {
			print_err_msg("Could not create renderer.");
			return false;
		}

		m_texture = SDL_CreateTexture(m_renderer,
				SDL_PIXELFORMAT_RGBA8888,
				SDL_TEXTUREACCESS_STATIC,
				SCREEN_WIDTH,
				SCREEN_HEIGHT);

		// check for errors
		if(m_texture == NULL) {
			print_err_msg("Could not create texture.");
			return false;
		}

		// declared by SDL
		// should represent 32bit int
		m_buffer = new Uint32[SCREEN_WIDTH * SCREEN_HEIGHT];

		memset(m_buffer, 
				133, 
				SCREEN_WIDTH * SCREEN_HEIGHT *sizeof(Uint32));

		for(int i=0; i<SCREEN_WIDTH*SCREEN_HEIGHT; i++) {
			m_buffer[i] = 0x00FF00FF;
		}

		render();

		// finally, if all passed
		return true;
	}

	bool Screen::process_events() const {
		SDL_Event event;
		// Check for messages & events
		while(SDL_PollEvent(&event)) {

			if(event.type == SDL_QUIT) return false;

			// window events
			if(event.type == SDL_WINDOWEVENT) {
				if(event.window.event == SDL_WINDOWEVENT_RESIZED) {
					render();
				}
			}
		}

		// everything went fine, continue
		return true;
	}

	void Screen::render() const {
		SDL_UpdateTexture(m_texture, 
				NULL, 
				m_buffer, 
				SCREEN_WIDTH * sizeof(Uint32));
		SDL_RenderClear(m_renderer);
		SDL_RenderCopy(m_renderer, m_texture, NULL, NULL);
		SDL_RenderPresent(m_renderer); // do the rendering
	}

	void Screen::close() {
		// dispose
		del_arr(m_buffer);

		SDL_DestroyRenderer(m_renderer);
		SDL_DestroyTexture(m_texture);
		SDL_DestroyWindow(m_window);

		// quit
		SDL_Quit();
	}

	void Screen::print_err_msg(std::string msg) const {
		cout << "ERR: " << msg << endl;
	}

	/*
	 *	Manipulate pixels
	 *
	 */
	void Screen::set_pixel(const int x, 
			const int y, 
			const Color color) const {
		m_buffer[(y * SCREEN_WIDTH) + x] = color.get_rgb();
		render();
	}

	void Screen::set_pixel_sq(const int x, 
			const int y,
			const int d, 
			const Color color) const {
		for(int h=y; h<y+d; h++) {
			for(int w=x; w<x+d; w++) {
				m_buffer[(h * SCREEN_WIDTH) + w] = color.get_rgb();
			}
		}
		// render();
	}

}
