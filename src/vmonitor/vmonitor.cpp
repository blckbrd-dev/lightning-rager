#include <iostream>
#include <cstdlib>
#include <cmath>

#include "vmonitor.h"
#include "paths.h"
#include "luabind.h"

namespace vmonitor {
	lbind::LuaState lstate;

	VMonitor::VMonitor(): m_lua_state(new sel::State()) {
		// manage LUA state
		lbind::LuaStackProtect _lstate(&lstate);

		// testing, will have a ui events that
		// load different scripts 
		std::string config_path(full_path);
		config_path += "/lua/config.lua";
		// m_lua_state->Load(script_path.c_str());

	
		// load configuration file	
		int _w = 800;
		int _h = 600;

		lstate.load_config(config_path.c_str(), 
				&_w, 
				&_h,
				&cell_size); 	

		if(!_init(_w, _h)) {
			init_fail = true;
			close();
		}

	}

	VMonitor::~VMonitor() {
		std::cout << "Destroyed VMonitor object. " << std::endl;
		delete m_lua_state;
	}

	cell VMonitor::find_cell(const int x, const int y) const {
		cell c;
		c.x = (x / cell_size) * cell_size; // integer division
		c.y = (y / cell_size) * cell_size; // integer division
		return c;
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

		// get initial state
		if(!m_drawing) {
			SDL_GetMouseState(&m_mouse_x, &m_mouse_y);
			m_drawing = true;
		}
	}

	void VMonitor::on_mouse_up() const {
		// this ends drawing
		m_drawing = false;
		Color clr;
		clr.set_rgb(255, 0, 0);

		int x, y;
		SDL_GetMouseState(&x, &y);

		// cell c = find_cell(x, y);
		// set_pixel_sq(c.x, c.y, cell_size, clr);

		// call lua draw & retrieve pixel matrix
		std::string test_p(full_path);
		test_p += "/lua/test.lua";

		luaL_openlibs(lstate.L);
		if(luaL_loadfile(lstate.L, test_p.c_str()) || lua_pcall(lstate.L, 0, 0, 0)) {
			std::cout << "Error loading file!" << std::endl;
			return;
		}

		lua_getglobal(lstate.L, "draw");

		cell start_mouse = find_cell(m_mouse_x, m_mouse_y);
		cell curr_mouse = find_cell(x, y);

		lua_pushnumber(lstate.L, start_mouse.x);
		lua_pushnumber(lstate.L, start_mouse.y);
		lua_pushnumber(lstate.L, curr_mouse.x);
		lua_pushnumber(lstate.L, curr_mouse.y);

		if(lua_pcall(lstate.L, 4, 0, 0) != LUA_OK) {
			std::cout << "Error calling lua function!" << std::endl;
			std::cout << lua_tostring(lstate.L, -1) << std::endl;
		}

		// get matrix
		std::vector<int> matrix;
		std::string name = "pixel_matrix";

		lua_settop(lstate.L, 0);

		lua_getglobal(lstate.L, name.c_str());

		if(lua_isnil(lstate.L, -1))
			std::cout << "Table empty!" << std::endl;

		lua_pushnil(lstate.L);

		if(!lua_checkstack(lstate.L, 800*600))
			std::cout << "Stack not large enough!" << std::endl;

		while(lua_next(lstate.L, -2)) {
			int temp = (int)lua_tonumber(lstate.L, -1);
			std::cout << temp << " ";
			matrix.push_back(temp);
			// set_pixel_sq(c.x, c.y, cell_size, clr);
			
			lua_pop(lstate.L, 1);
		}

		std::cout << std::endl;

		for(int i=0; i<60; i++) {
			for(int j=0; j<80; j++) {
				if(matrix[(i * 80) + j] == 1) {
					cell c = find_cell(j, i);
					set_pixel_sq(j*10, i*10, 10, clr);
				}
				// std::cout << matrix[(i*80) + j] << " ";	
			}
			//std::cout << std::endl;
		}

		lua_settop(lstate.L, 0);

		std::cout << "Called mouse up" << std::endl;
	}

	void VMonitor::on_mouse_move() const {}

	void VMonitor::on_mouse_drag() const {

	}	

	bool VMonitor::init() const {
		return !init_fail;
	}
}
