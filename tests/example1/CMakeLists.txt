find_package(Boost COMPONENTS unit_test_framework REQUIRED)
add_executable(example1 main.cpp)
target_link_libraries(example1 ${Boost_LIBRARIES} pMesh)
message(STATUS "build example1")