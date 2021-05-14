find_package(Boost COMPONENTS unit_test_framework REQUIRED)
find_package(OpenMP)

add_executable(tri_tri_inter tri_tri_intersection.h main.cpp)
target_link_libraries(tri_tri_inter ${Boost_LIBRARIES} pMesh OpenMP::OpenMP_CXX)
message(STATUS "build tri_tri_inter")