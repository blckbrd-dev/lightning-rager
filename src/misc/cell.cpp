#include "cell.h"

namespace vmonitor {
	Cell::Cell() {
		x = -1;
		y = -1;
	}
	
	Cell::Cell(const Uint16 _x, const Uint16 _y) {
		x = _x;
		y = _y;		
	}

	inline void Cell::set_x(const Uint16 _x) const { x = _x; }

	inline void Cell::set_y(const Uint16 _y) const { y = _y; }
	
}
