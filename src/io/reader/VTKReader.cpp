/**
 * ------------------------------------
 * @author: Weipeng Kong
 * @date: 2021/5/12
 * @email: yjxkwp@foxmail.com
 * @site: https://x86.design
 * @description: 
 * ------------------------------------
**/

#include <pMesh/io/reader/VTKReader.h>

#include <vtkActor.h>
#include <vtkNamedColors.h>
#include <vtkNew.h>
#include <vtkPolyData.h>
#include <vtkCellData.h>
#include <vtkDoubleArray.h>
#include <vtkPolyDataMapper.h>
#include <vtkProperty.h>
#include <vtkRenderWindow.h>
#include <vtkPointData.h>
#include <vtkRenderWindowInteractor.h>
#include <vtkRenderer.h>
#include <vtkSTLReader.h>
#include <vtkSTLWriter.h>
#include <vtkCellArray.h>
#include <vtkNew.h>
#include <vtkPolygon.h>
#include <vtkPoints.h>
#include <vtkSmartPointer.h>
#include <vtkUnstructuredGrid.h>
#include <vtkUnstructuredGridWriter.h>
#include <vtkUnstructuredGridReader.h>

pMesh::io::VTKReader::VTKReader(const fs_path &path) : path(path){}

bool pMesh::io::VTKReader::operator>>(ReadAdapter &adapter) {
    adapter.start();
    vtkNew<vtkUnstructuredGridReader> reader;
    reader->SetFileName(path.c_str());
    reader->Update();
    auto data = reader->GetOutput();
    int point_n, cell_n;
    point_n = data->GetNumberOfPoints();
    cell_n = data->GetNumberOfCells();
    for (int i = 0; i < point_n; ++i) {
        adapter.feed_vertex(Point3d(data->GetPoint(i)));
    }
    for (int i = 0; i < cell_n; ++i) {
        auto cell = data->GetCell(i);
        std::vector<int> c;
        c.reserve(cell->GetNumberOfPoints());
        for(int j = 0; j < cell->GetNumberOfPoints(); ++j){
            c.push_back((int)cell->GetPointId(j));
        }
        adapter.feed_collection(c);
    }
    adapter.end();
    return true;
}