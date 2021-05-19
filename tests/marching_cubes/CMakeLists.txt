find_package(Boost COMPONENTS unit_test_framework REQUIRED)
add_executable(marching_cubes main.cpp)
target_link_libraries(marching_cubes ${Boost_LIBRARIES} pMesh)
message(STATUS "build marching_cubes")