cmake_minimum_required(VERSION 3.10.3 FATAL_ERROR)

# ------------------------------------------------------------------------------
# PROJECT METADATA
# ------------------------------------------------------------------------------

project(UnionFindWithSpecificCanonicalElement VERSION 1.0 LANGUAGES CXX)

set(CMAKE_CXX_FLAGS "-std=c++11")
if ("${CMAKE_BUILD_TYPE}" STREQUAL "Debug")
   set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -g")
endif()

# ------------------------------------------------------------------------------
# EXTERNAL RESOURCES
# ------------------------------------------------------------------------------

# ------------------------------------------------------------------------------
# DEFINE PRODUCTION LIBRARY
# ------------------------------------------------------------------------------

include_directories("${PROJECT_SOURCE_DIR}/src/main/include")

set(HDR_DIR "${PROJECT_SOURCE_DIR}/src/main/include")

file( GLOB
      PROD_IMPL_FILES
      "${PROJECT_SOURCE_DIR}/src/main/C++/*.cpp"
)

add_library( unionfindwithspecificcanonicalelement-lib
	     SHARED
	     "${PROD_IMPL_FILES}"
)

set(INCLUDE_INSTALL_DIR "${PROJECT_SOURCE_DIR}/include/${CMAKE_BUILD_TYPE}")

set(LIB_INSTALL_DIR "${PROJECT_SOURCE_DIR}/lib/${CMAKE_BUILD_TYPE}")
if (NOT EXISTS "${LIB_INSTALL_DIR}")
   file(MAKE_DIRECTORY "${LIB_INSTALL_DIR}")
endif()

# ------------------------------------------------------------------------------
# INSTALLATION RULES
# ------------------------------------------------------------------------------

install(DIRECTORY "${HDR_DIR}"
        DESTINATION "${PROJECT_SOURCE_DIR}"
        FILES_MATCHING PATTERN "*.h"
)

install( TARGETS unionfindwithspecificcanonicalelement-lib
	 LIBRARY
	 DESTINATION "${LIB_INSTALL_DIR}"
)

# ------------------------------------------------------------------------------
# DEFINE TEST EXECUTABLE
# ------------------------------------------------------------------------------

file( GLOB
      TEST_IMPL_FILES
      "${PROJECT_SOURCE_DIR}/src/test/C++/*.cpp"
)

add_executable( UnionFindWithSpecificCanonicalElementTests
                "${TEST_IMPL_FILES}"
)

add_library( gtest
             STATIC
             IMPORTED
)

set_property( TARGET gtest
              PROPERTY
              IMPORTED_LOCATION
              "/usr/local/lib/libgtest.a"
)

target_include_directories( UnionFindWithSpecificCanonicalElementTests
                            PUBLIC "${PROJECT_SOURCE_DIR}/src/test/include"
)

target_link_libraries( UnionFindWithSpecificCanonicalElementTests
                       LINK_PUBLIC unionfindwithspecificcanonicalelement-lib
                       LINK_PUBLIC gtest
)

# ------------------------------------------------------------------------------
# RUN TESTS
# ------------------------------------------------------------------------------

set (RUN_UNIT_TESTS TRUE CACHE BOOL "Run the unit tests.")

set(TEST_RESOURCES_DIR "${PROJECT_SOURCE_DIR}/src/test/resources")

if (RUN_UNIT_TESTS)
  add_custom_command(
      TARGET UnionFindWithSpecificCanonicalElementTests
      COMMENT "Running Unit Tests..."
      POST_BUILD
      COMMAND ./UnionFindWithSpecificCanonicalElementTests "${TEST_RESOURCES_DIR}"
  )
endif()
