#include <iostream>
#include <SDL.h>

#include "vmonitor.h"

using std::cout;
using std::endl;

int main() {
	// const vmonitor::Screen screen;

	const vmonitor::VMonitor vm;

	while(vm.process_events()) {
		// do something
	}

	return 0;
}
