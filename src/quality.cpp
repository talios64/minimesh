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

  // Visualize
  auto mapper = vtkSmartPointer<vtkDataSetMapper>::New();
  mapper->SetInputData(dataset);
  mapper->SetScalarRange(dataset->GetScalarRange());

  auto actor = vtkSmartPointer<vtkActor>::New();
  actor->SetMapper(mapper);

  auto renderer = vtkSmartPointer<vtkRenderer>::New();

  auto renderWindow =vtkSmartPointer<vtkRenderWindow>::New();
  renderWindow->AddRenderer(renderer);

  auto renderWindowInteractor = vtkSmartPointer<vtkRenderWindowInteractor>::New();
  renderWindowInteractor->SetRenderWindow(renderWindow);

  renderer->AddActor(actor);
  renderer->SetBackground(.3, .6, .3); // Background color green

  renderWindow->Render();
  renderWindowInteractor->Start();
}


