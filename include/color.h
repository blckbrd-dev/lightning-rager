#ifndef COLOR_H_
#define COLOR_H_
namespace vmonitor {
class Color {
private:
	mutable int m_color;
public:
	int get_rgb() const;
	void set_rgb(const int color) const;
};
}
#endif
