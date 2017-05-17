#include <iostream>
#include <SDL.h>

#define del(x) { delete x; x = NULL; }
#define del_arr(x) { delete [] x; x = NULL };

#include "vmonitor.h"

using std::cout;
using std::endl;

void dealocate();

int main() {
	// const vmonitor::Screen screen;
	const vmonitor::VMonitor vm;

	bool keep_running = vm.init();
	while(keep_running) {
		// events, watch for quit event
		keep_running = vm.process_events();
	}

	vm.close();
	return 0;
}
