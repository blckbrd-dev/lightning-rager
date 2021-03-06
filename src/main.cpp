#include <iostream>
#include <SDL.h>

#include "vmonitor.h"

using std::cout;
using std::endl;

int main() {
	// const vmonitor::Screen screen;
	const vmonitor::VMonitor vm;

	bool keep_running = true;
	while(keep_running) {
		// events, watch for quit event
		keep_running = vm.process_events();
	}

	return 0;
}
