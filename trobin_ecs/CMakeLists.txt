# CMakeList.txt : CMake project for trobin_ecs, include source and define
# project specific logic here.
#

# Add source to this project's executable.
add_executable (trobin_ecs "src/main.cpp" "src/main.h" "src/practice/StdTemplatePractice.cpp"   "src/engine/EntityManager.h" "src/engine/Logger.h" "src/engine/Timer.h" "src/engine/Profiler.h"    "src/test/TstTimer.h" "src/practice/MemoryPool.h" "src/engine/Archetype.h" "src/practice/Metaprogramming.h" "src/practice/TemplateMeta_1.h" "src/practice/TemplateMeta_2.h"  "src/ecs/Components.h" "src/utils/MathUtils.cpp" "src/utils/MathUtils.h" "src/engine/MetaArchetype.h" "src/engine/ArchetypeManager.h")

if (CMAKE_VERSION VERSION_GREATER 3.12)
  set_property(TARGET trobin_ecs PROPERTY CXX_STANDARD 20)
endif()

# TODO: Add tests and install targets if needed.
