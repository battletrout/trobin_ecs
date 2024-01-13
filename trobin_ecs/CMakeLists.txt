# CMakeList.txt : CMake project for trobin_ecs, include source and define
# project specific logic here.
#

# Add source to this project's executable.
add_executable (trobin_ecs "trobin_ecs.cpp" "trobin_ecs.h")

if (CMAKE_VERSION VERSION_GREATER 3.12)
  set_property(TARGET trobin_ecs PROPERTY CXX_STANDARD 20)
endif()

# TODO: Add tests and install targets if needed.
