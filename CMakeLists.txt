cmake_minimum_required(VERSION 3.19)
project(pMesh)

set(CMAKE_CXX_STANDARD 14)

option(pMesh_BUILD_TEST  "Build test projects" ON)

file(GLOB headers ${CMAKE_CURRENT_SOURCE_DIR}/include/pMesh/*.h)
file(GLOB sources ${CMAKE_CURRENT_SOURCE_DIR}/src/*.cpp)

find_package(Boost COMPONENTS filesystem log REQUIRED)
find_package(Eigen3 3.3 REQUIRED NO_MODULE)

add_library(pMesh SHARED ${headers} ${sources})
target_link_libraries(pMesh PUBLIC ${Boost_LIBRARIES} Eigen3::Eigen)
target_include_directories(pMesh PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/include)


# install
install(FILES ${headers} DESTINATION include/pMesh)
install(TARGETS pMesh ARCHIVE DESTINATION lib)

# build test
if(pMesh_BUILD_TEST)
    add_subdirectory(${CMAKE_CURRENT_SOURCE_DIR}/tests/example1)
endif()

# tests
enable_testing()
if(pMesh_BUILD_TEST)
    add_test(NAME example1 COMMAND $<TARGET_FILE:example1>)
endif()