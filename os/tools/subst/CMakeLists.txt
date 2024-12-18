cmake_minimum_required(VERSION 3.5)
project(subst)

set(CMAKE_CXX_STANDARD 14)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# add_executable(brx brx.cc)
# add_executable(escp escp.cc)
add_executable(subst main.cc subst.cc)
add_library(subst1 subst.cc)
add_executable(testcall caller.c)
target_link_libraries(testcall subst1)
# target_include_directories(brx PRIVATE boost_1_86_0)
target_include_directories(subst1 PRIVATE boost_1_86_0)
target_include_directories(subst PRIVATE boost_1_86_0)

# include(FetchContent)
# FetchContent_Declare(
#   googletest
#   URL https://github.com/google/googletest/archive/03597a01ee50ed33e9dfd640b249b4be3799d395.zip
# )

# FetchContent_MakeAvailable(googletest)

# enable_testing()

# add_executable(
#   tests
#   tests.cc
#   subst.cc
# )

# target_include_directories(tests PRIVATE boost_1_86_0)
# target_link_libraries(
#   tests
#   GTest::gtest_main
# )

# include(GoogleTest)
# gtest_discover_tests(tests)

install(TARGETS subst DESTINATION bin)
install(FILES subst.sh DESTINATION bin
  PERMISSIONS OWNER_EXECUTE OWNER_WRITE OWNER_READ
                    GROUP_EXECUTE GROUP_READ)
install(TARGETS subst1 DESTINATION lib)
install(FILES "subst.h"
  DESTINATION include
  )
