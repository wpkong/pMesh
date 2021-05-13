/**
 * ------------------------------------
 * @author: Weipeng Kong
 * @date: 2021/5/13
 * @email: yjxkwp@foxmail.com
 * @site: https://x86.design
 * @description: 
 * ------------------------------------
**/

#include <pMesh/io/writers/STLWriter.h>

#include <vtkActor.h>
#include <vtkNamedColors.h>
#include <vtkNew.h>
#include <vtkPolyData.h>
#include <vtkPolyDataMapper.h>
#include <vtkProperty.h>
#include <vtkRenderWindow.h>
#include <vtkRenderWindowInteractor.h>
#include <vtkRenderer.h>
#include <vtkSTLReader.h>
#include <vtkSTLWriter.h>
#include <vtkUnstructuredGrid.h>

pMesh::io::STLWriter::STLWriter(const pMesh::io::fs_path &path): path(path) {}

bool pMesh::io::STLWriter::operator<<(pMesh::io::WriteAdapter &adapter) {
    return true;
}
