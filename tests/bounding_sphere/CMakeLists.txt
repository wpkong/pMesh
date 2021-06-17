find_package(Boost COMPONENTS unit_test_framework REQUIRED)
add_executable(bounding_sphere main.cpp)
target_link_libraries(bounding_sphere ${Boost_LIBRARIES} pMesh)
message(STATUS "build bounding_sphere")