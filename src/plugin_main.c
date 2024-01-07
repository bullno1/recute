#include <cute_app.h>
#include <cute_draw.h>
#include <cute_math.h>
#define REMODULE_PLUGIN_IMPLEMENTATION
#include <remodule.h>
#include "plugin_interface.h"
#include <cute.h>

static void
update(void) {
	cf_app_update(NULL);
	cf_draw_box(
		cf_make_aabb(
			cf_v2(10.f, 10.f),
			cf_v2(200.f, 100.f)
		),
		2.4f,
		4.0f
	);
	cf_app_draw_onto_screen(true);
}

static void
register_plugin(plugin_interface_t* plugin_interface) {
	plugin_interface->update = update;
}

void
remodule_entry(remodule_op_t op, void* userdata) {
	plugin_interface_t* plugin_interface = userdata;

	switch (op) {
		case REMODULE_OP_LOAD:
			register_plugin(plugin_interface);
			break;
		case REMODULE_OP_UNLOAD:
			break;
		case REMODULE_OP_BEFORE_RELOAD:
			break;
		case REMODULE_OP_AFTER_RELOAD:
			register_plugin(plugin_interface);
			break;
	}
}
