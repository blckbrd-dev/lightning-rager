#include <SDL_pixels.h>

#ifndef CELL_H_
#define CELL_H_
namespace vmonitor {
class Cell {
public:
	mutable Uint16 x, y;
public:
	Cell();
	Cell(const Uint16, const Uint16);
	inline void set_x(const Uint16) const;
	inline void set_y(const Uint16) const;
};
}
#endif
