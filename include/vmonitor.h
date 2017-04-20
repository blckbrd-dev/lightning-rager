#include "screen.h"
#include "cell.h"

#pragma once

namespace vmonitor {

class VMonitor: public vmonitor::Screen {
private:
	mutable Uint32** matrix;
	mutable Uint32* m_buffer;
private:
	cell find_cell(const int, const int) const;
public:
	static const int CELL_SIZE = SCREEN_WIDTH / 100;
<<<<<<< HEAD
	void on_mouse_down() const override;
=======
>>>>>>> 0914a9e98e95838969e1b43a166969e05b2ca102
public:
	VMonitor();
};
}
