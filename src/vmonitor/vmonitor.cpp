#include <iostream>
#include <cstdlib>
#include <cmath>

#include "vmonitor.h"

namespace vmonitor {
	VMonitor::VMonitor() {

	}

	cell VMonitor::find_cell(const int x, const int y) const {
		cell c;
		c.x = (x / CELL_SIZE) * CELL_SIZE; // integer division
		c.y = (y / CELL_SIZE) * CELL_SIZE; // integer division
		return c;
	}

	/* **************
	 *							*
	 * MOUSE EVENTS *
	 *							*
	 * **************
	 *//////////////////////////////////////////////////////////////////////////
	void VMonitor::on_mouse_down() const {
		// std::cout << "Mouse button pressed." << std::endl;
		// now, change color of the pixel
		// Color clr;
		// clr.set_rgb(255, 0, 0);

		// int x, y;
		// SDL_GetMouseState(&x, &y);

		// cell c = find_cell(x, y);
		// set_pixel_sq(c.x, c.y, VMonitor::CELL_SIZE, clr);
		// 
		// initialize drawing
		m_drawing = true;
		SDL_GetMouseState(&m_mouse_X, &m_mouse_y);
	}

	void VMonitor::on_mouse_up() const {
		// this ends drawing
		m_drawing = false;
	}

	void VMonitor::on_mouse_move() const {}

	void VMonitor::on_mouse_drag() const {
		Color clr;
		clr.set_rgb(255, 0, 0);

		int x, y;
		SDL_GetMouseState(&x, &y);

		cell c = find_cell(x, y);
		set_pixel_sq(c.x, c.y, VMonitor::CELL_SIZE, clr);
		std::cout << "drawing? " << m_drawing << std::endl;

		// while mouse is being dragged
		// we want to draw shapes here...
	}	
}
