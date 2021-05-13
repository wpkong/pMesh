find_package(Boost COMPONENTS unit_test_framework REQUIRED)
find_package(OpenMP)

add_executable(simplify_edges preprocess.h utils.h main.cpp)
target_link_libraries(simplify_edges ${Boost_LIBRARIES} pMesh OpenMP::OpenMP_CXX)
message(STATUS "build simplify_edges")