#include "screen.h"
#include "cell.h"

#ifndef VMONITOR_H_
#define VMONITOR_H_

namespace vmonitor {

class VMonitor: public vmonitor::Screen {
private:
	mutable Uint32** matrix;
	mutable Uint32* m_buffer;
private:
	Cell find_cell(const int, const int) const;
public:
	static const int CELL_SIZE = SCREEN_WIDTH / 100;
	static const int WIDTH = SCREEN_WIDTH / (SCREEN_WIDTH / 100);
	static const int HEIGHT = SCREEN_HEIGHT / (SCREEN_WIDTH / 100);
public:
	VMonitor();
	void set_matrix(Uint32**) const;
};
}
#endif
