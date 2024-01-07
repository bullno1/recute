#include <cute.h>

int
main(int argc, const char* argv[]) {
	(void)argc;
	// Create a window with a resolution of 640 x 480.
	int options = CF_APP_OPTIONS_DEFAULT_GFX_CONTEXT | CF_APP_OPTIONS_WINDOW_POS_CENTERED;
	CF_Result result = cf_make_app("Fancy Window Title", 0, 0, 640, 480, options, argv[0]);
	if (cf_is_error(result)) return -1;

	while (cf_app_is_running())
	{
		cf_app_update(NULL);
		// All your game logic and updates go here...
		cf_app_draw_onto_screen(true);
	}

	cf_destroy_app();

	return 0;
}
