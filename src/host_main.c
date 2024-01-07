#define REMODULE_HOST_IMPLEMENTATION
#define REMODULE_MONITOR_IMPLEMENTATION
#include <remodule.h>
#include <remodule_monitor.h>
#include <cute.h>
#include "plugin_interface.h"

int
main(int argc, const char* argv[]) {
	(void)argc;
	// Create a window with a resolution of 640 x 480.
	int options = CF_APP_OPTIONS_DEFAULT_GFX_CONTEXT | CF_APP_OPTIONS_WINDOW_POS_CENTERED;
	CF_Result result = cf_make_app(
		"Fancy Window Title", 0, 0, 640, 480, options, argv[0]
	);

	if (cf_is_error(result)) {
		return -1;
	}

	plugin_interface_t plugin_interface = { 0 };
	remodule_t* module = remodule_load(
		"./recute_plugin" REMODULE_DYNLIB_EXT,
		&plugin_interface
	);
	remodule_monitor_t* monitor = remodule_monitor(module);

	while (cf_app_is_running()) {
		if (plugin_interface.update != NULL) {
			plugin_interface.update();
		}

		remodule_check(monitor);
	}

	remodule_unmonitor(monitor);
	remodule_unload(module);

	cf_destroy_app();

	return 0;
}
