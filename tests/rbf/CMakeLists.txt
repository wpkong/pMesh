find_package(Boost COMPONENTS unit_test_framework REQUIRED)
add_executable(rbf main.cpp)
target_link_libraries(rbf ${Boost_LIBRARIES} pMesh)
message(STATUS "build rbf")