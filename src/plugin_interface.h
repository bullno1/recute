#ifndef PLUGIN_INTERFACE_H
#define PLUGIN_INTERFACE_H

typedef struct plugin_interface_s {
	void (*update)(void);
} plugin_interface_t;

#endif
