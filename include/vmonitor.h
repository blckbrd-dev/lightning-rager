#include "screen.h"
#include "cell.h"

#pragma once

namespace vmonitor {
class VMonitor: public vmonitor::Screen {
private:
	mutable int m_mouse_X;
	mutable int m_mouse_y;
private:
	cell find_cell(const int, const int) const;
	void on_mouse_down()	const override;
	void on_mouse_up()		const override;
	void on_mouse_move()	const override;
	void on_mouse_drag()	const override;
public:
	static const int CELL_SIZE = SCREEN_WIDTH / 60;
public:
	VMonitor();
};
}
