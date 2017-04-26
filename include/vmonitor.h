#include "screen.h"
#include "cell.h"
#include "selene.h"

#pragma once

namespace vmonitor {
class VMonitor: public vmonitor::Screen {
private:
	mutable int m_mouse_X;
	mutable int m_mouse_y;
	sel::State* const m_lua_state;
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
	~VMonitor();
};
}
