#include <iostream>
#include <cstdlib>
#include <cmath>

#include "vmonitor.h"
#include "paths.h"
#include "luabind.h"

namespace vmonitor {
	VMonitor::VMonitor(): m_lua_state(new sel::State()) {
		// manage LUA state
		lbind::LuaState lstate;
		lbind::LuaStackProtect _lstate(&lstate);

		// testing, will have a ui events that
		// load different scripts 
		std::string script_path(full_path);
		script_path += "/lua/config.lua";
		// m_lua_state->Load(script_path.c_str());

	
		// load configuration file	
		int _w = 800;
		int _h = 600;

		lstate.load_config(script_path.c_str(), 
				&_w, 
				&_h,
				&cell_size); 	

		if(!init(_w, _h))
			close();

	}

	cell VMonitor::find_cell(const int x, const int y) const {
		cell c;
		c.x = (x / cell_size) * cell_size; // integer division
		c.y = (y / cell_size) * cell_size; // integer division
		return c;
	}

	VMonitor::~VMonitor() {
		std::cout << "Destroyed VMonitor object. " << std::endl;
		delete m_lua_state;
	}

	/* **************
	 *							*
	 * MOUSE EVENTS *
	 *							*
	 * **************
	 *//////////////////////////////////////////////////////////////////////////
	void VMonitor::on_mouse_down() const {
		// std::cout << "Mouse button pressed." << std::endl;
		// now, change color of the pixel
		// Color clr;
		// clr.set_rgb(255, 0, 0);

		// int x, y;
		// SDL_GetMouseState(&x, &y);

		// cell c = find_cell(x, y);
		// set_pixel_sq(c.x, c.y, VMonitor::cell_size, clr);
		// 
		// initialize drawing
		m_drawing = true;
		SDL_GetMouseState(&m_mouse_X, &m_mouse_y);
	}

	void VMonitor::on_mouse_up() const {
		// this ends drawing
		m_drawing = false;
	}

	void VMonitor::on_mouse_move() const {}

	void VMonitor::on_mouse_drag() const {
		Color clr;
		clr.set_rgb(255, 0, 0);

		int x, y;
		SDL_GetMouseState(&x, &y);

		cell c = find_cell(x, y);
		set_pixel_sq(c.x, c.y, cell_size, clr);

		// while mouse is being dragged
		// we want to draw shapes here...
		// check for function
		// std::string fn_log = (*m_lua_state)["draw"]();
		// std::cout << "From LUA: " << fn_log << std::endl;
	}	
}
