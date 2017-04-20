#include "color.h"

namespace vmonitor {
	int Color::get_rgb() const {
		return m_color;
	}

	Uint8 Color::get_r() const {
		return get_byte(m_color, 3);
	}

	Uint8 Color::get_g() const {
		return get_byte(m_color, 2);
	}

	Uint8 Color::get_b() const {
		return get_byte(m_color, 1);
	}

	Uint8 Color::get_a() const {
		return get_byte(m_color, 0);
	}

	Uint8 Color::get_byte(const int n, const Uint8 pos) const {
		return static_cast<Uint8>((n << (8 * pos)) & 0xff);
	}

	void Color::set_rgb(const Uint8 r, const Uint8 g, const Uint8 b) const {
		int color = 0;
		color += r;
		color <<= 8;
		color += g;
		color <<= 8;
		color += b;
		color <<= 8;

		// finally, set color
		m_color = color;
	}
}
