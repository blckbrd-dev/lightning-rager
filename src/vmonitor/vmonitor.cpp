#include <iostream>
#include <cstdlib>
#include <ctime>
#include <cmath>

#include "vmonitor.h"

namespace vmonitor {
	VMonitor::VMonitor(): matrix(NULL) {

		// init matrix
		// matrix = new Uint32*[HEIGHT];
		// for(int i=0; i<HEIGHT; i++) matrix[i] = new Uint32[WIDTH];
		Color clr;
		clr.set_rgb(125);

		// set_pixel_sq(100, 8, c);

		// TEST
		// randomly populate with squares
		srand(time(NULL));
		Cell c = find_cell(599, 599);
		set_pixel_sq(c.x, c.y, VMonitor::CELL_SIZE, clr);
		Cell c1 = find_cell(76, 76);
		set_pixel_sq(c1.x, c1.y, VMonitor::CELL_SIZE, clr);
		render();
		// END
	}

	void VMonitor::set_matrix(Uint32**) const {
		// Uint32* buffer = new Uint32[SCREEN_WIDTH * SCREEN_HEIGHT];

	}

	Cell VMonitor::find_cell(const int x, const int y) const {
		Cell c;
		c.x = floor(x / CELL_SIZE) * CELL_SIZE; // integer division
		c.y = floor(y / CELL_SIZE) * CELL_SIZE; // integer division
		return c;
	}
}
