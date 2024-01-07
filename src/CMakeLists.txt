set(CMAKE_SKIP_BUILD_RPATH FALSE)
set(CMAKE_BUILD_WITH_INSTALL_RPATH TRUE)
set(CMAKE_INSTALL_RPATH "\${ORIGIN}")

add_executable(recute "main.c")
target_link_libraries(recute PRIVATE
	cute  # :">
)
