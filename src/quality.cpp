#include <memory>

#include "viewer.hpp"
#include "options.hpp"
#include "quality.hpp"

#include <vtkSmartPointer.h>
#include <vtkActor.h>
#include <vtkDataSetMapper.h>
#include <vtkRenderWindow.h>
#include <vtkRenderWindowInteractor.h>
#include <vtkRenderer.h>
#include <vtkProperty.h>
#include <vtkDataSet.h>
#include <vtkMeshQuality.h>
#include <vtkDoubleArray.h>
#include <vtkPointData.h>
#include <vtkCellData.h>
#include <vtkPolyData.h>

QualityChecker::QualityChecker(){}

void QualityChecker::Quality_Analysis(vtkSmartPointer<vtkDataSet> dataset)
{
    std::cout <<"There are " << dataset->GetNumberOfCells() << " Cells \n";

    auto qualityFilter = vtkSmartPointer<vtkMeshQuality>::New();
    qualityFilter->SetInputData(dataset);
    qualityFilter->SetTriangleQualityMeasureToArea();
    qualityFilter->Update();
    // qualityFilter->SetTriangleQualityMeasure(VTK_QUALITY_SHAPE_AND_SIZE);

    vtkSmartPointer<vtkDoubleArray> qualityArray =
    dynamic_cast<vtkDoubleArray*>(qualityFilter->GetOutput()->GetCellData()->GetArray("Quality"));

    for(vtkIdType i = 0; i < qualityArray->GetNumberOfTuples(); i++)
    {
        double val = qualityArray->GetValue(i);
        std::cout << "value " << i << " : " << val << std::endl;
    }
    // std::cout << "mesure qualité : " << qualityFilter->GetTriangleQualityMeasure() << std::endl;
}


