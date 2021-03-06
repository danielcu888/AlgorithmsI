cmake_minimum_required(VERSION 3.10.3)

# ------------------------------------------------------------------------------
# PROJECT METADATA
# ------------------------------------------------------------------------------

project(SocialConnectivity)

set(CMAKE_CXX_FLAGS "-std=c++11")
if ("${CMAKE_BUILD_TYPE}" STREQUAL "Debug")
   set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -g")
endif()

# ------------------------------------------------------------------------------
# EXTERNAL RESOURCES
# ------------------------------------------------------------------------------

add_library( boost_system
             STATIC
             IMPORTED
)

set_property( TARGET boost_system
              PROPERTY
              IMPORTED_LOCATION
              "/usr/local/lib/libboost_system.a"
)

add_library( boost_filesystem
             STATIC
             IMPORTED
)

set_property( TARGET boost_filesystem
              PROPERTY
              IMPORTED_LOCATION
              "/usr/local/lib/libboost_filesystem.a"
)

add_library( boost_date_time
             STATIC
             IMPORTED
)

set_property( TARGET boost_date_time
              PROPERTY
              IMPORTED_LOCATION
              "/usr/local/lib/libboost_date_time.a"
)

# ------------------------------------------------------------------------------
# DEFINE PRODUCTION LIBRARY
# ------------------------------------------------------------------------------

include_directories("${PROJECT_SOURCE_DIR}/src/main/include")

set(HDR_DIR "${PROJECT_SOURCE_DIR}/src/main/include")

file( GLOB
      PROD_IMPL_FILES
      "${PROJECT_SOURCE_DIR}/src/main/C++/*.cpp"
)

add_library( social_connectivity
	     SHARED
	     "${PROD_IMPL_FILES}"
)

target_link_libraries ( social_connectivity
                        LINK_PUBLIC boost_system
                        LINK_PUBLIC boost_filesystem
                        LINK_PUBLIC boost_date_time
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

install( TARGETS social_connectivity
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

add_executable( SocialConnectivityTests
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

target_include_directories( SocialConnectivityTests
                            PUBLIC "${PROJECT_SOURCE_DIR}/src/test/include"
)

target_link_libraries( SocialConnectivityTests
                       LINK_PUBLIC social_connectivity
                       LINK_PUBLIC gtest
)

# ------------------------------------------------------------------------------
# RUN TESTS
# ------------------------------------------------------------------------------

set(TEST_RESOURCES_DIR "${PROJECT_SOURCE_DIR}/resources")

add_custom_command(
    TARGET SocialConnectivityTests
    COMMENT "Running Unit Tests..."
    POST_BUILD
    COMMAND ./SocialConnectivityTests "${TEST_RESOURCES_DIR}"
)
