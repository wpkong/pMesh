cmake_minimum_required(VERSION 3.19)
project(pMesh)

set(CMAKE_CXX_STANDARD 20)

option(pMesh_BUILD_TEST  "Build test projects" ON)

file(GLOB_RECURSE headers
        ${CMAKE_CURRENT_SOURCE_DIR}/include/pMesh/*.h
        ${CMAKE_CURRENT_SOURCE_DIR}/include/pMesh/*.impl
        )
file(GLOB_RECURSE sources ${CMAKE_CURRENT_SOURCE_DIR}/src/*.cpp)

find_package(Boost COMPONENTS filesystem log REQUIRED)
find_package(Eigen3 3.3 REQUIRED NO_MODULE)

# vtk lib
find_package(VTK COMPONENTS
        vtkCommonCore
        vtkCommonDataModel
        vtkIOGeometry
        vtkCommonCore
        vtkFiltersCore
        vtkFiltersExtraction
        vtkFiltersSources
        vtkFiltersGeneral
        vtkFiltersGeometry
        vtkInteractionStyle
        vtkIOGeometry
        vtkIOLegacy
        vtkIOPLY
        vtkIOXML
        vtkRenderingContextOpenGL2
        vtkRenderingCore
        vtkRenderingFreeType
        vtkRenderingGL2PSOpenGL2
        vtkRenderingOpenGL2
        vtkCommonColor
        vtkCommonCore
        vtkCommonDataModel
        vtkFiltersCore
        vtkFiltersExtraction
        vtkFiltersGeneral
        vtkFiltersGeometry
        vtkFiltersSources
        QUIET)
if (NOT VTK_FOUND)
    message("Skipping GenericDataObjectReader: ${VTK_NOT_FOUND_MESSAGE}")
    return ()
endif()
message (STATUS "VTK_VERSION: ${VTK_VERSION}")


add_library(pMesh SHARED ${headers} ${sources})
target_link_libraries(pMesh PUBLIC ${Boost_LIBRARIES} Eigen3::Eigen ${VTK_LIBRARIES})
target_include_directories(pMesh PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/include)


# install
install(FILES ${headers} DESTINATION include/pMesh)
install(TARGETS pMesh ARCHIVE DESTINATION lib)

# build test
if(pMesh_BUILD_TEST)
    add_subdirectory(${CMAKE_CURRENT_SOURCE_DIR}/tests/example1)
    add_subdirectory(${CMAKE_CURRENT_SOURCE_DIR}/tests/simplify_edges)
    add_subdirectory(${CMAKE_CURRENT_SOURCE_DIR}/tests/tri_tri_inter)

endif()

# tests
enable_testing()
if(pMesh_BUILD_TEST)
    add_test(NAME example1 COMMAND $<TARGET_FILE:example1>)
    add_test(NAME simplify_edges COMMAND $<TARGET_FILE:simplify_edges>)
    add_test(NAME tri_tri_inter COMMAND $<TARGET_FILE:tri_tri_inter>)
endif()