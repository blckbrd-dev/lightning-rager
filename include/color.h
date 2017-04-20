#include <SDL_types.h>

#pragma once
namespace vmonitor {
class Color {
private:
	mutable int m_color;
private:
	Uint8 get_byte(const int n, const Uint8 pos) const;
public:
	// colors are saved as an int
	int get_rgb() const;
	Uint8 get_r() const;
	Uint8 get_g() const;
	Uint8 get_b() const;
	Uint8 get_a() const;

	void set_rgb(const Uint8, const Uint8, const Uint8) const;
	void set_rgba(const Uint8, const Uint8, const Uint8, const Uint8) const;
};
}
