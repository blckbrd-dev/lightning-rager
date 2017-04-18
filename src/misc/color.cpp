#include "color.h"

namespace vmonitor {
	int Color::get_rgb() const {
		return m_color;
	}

	void Color::set_rgb(const int color) const {
		m_color = color;	
	}
}
