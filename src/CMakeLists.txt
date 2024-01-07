set(CMAKE_SKIP_BUILD_RPATH FALSE)
set(CMAKE_BUILD_WITH_INSTALL_RPATH TRUE)
set(CMAKE_INSTALL_RPATH "\${ORIGIN}")

setup_library(recute_plugin FALSE "plugin_main.c")
target_link_libraries(recute_plugin PRIVATE
	cute  # :">
	remodule
)
set_target_properties(recute_plugin PROPERTIES
	OUTPUT_NAME "recute_plugin"
	PREFIX ""
)

add_executable(recute "host_main.c")
target_link_libraries(recute PRIVATE
	cute  # :">
	remodule
)
