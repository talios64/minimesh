#include <memory>

#include "transform.hpp"
#include "options.hpp"

#include <vtkSmartPointer.h>
#include <vtkActor.h>
#include <vtkDataSetMapper.h>
#include <vtkRenderWindow.h>
#include <vtkRenderWindowInteractor.h>
#include <vtkRenderer.h>
#include <vtkProperty.h>
#include <vtkDataSet.h>
#include <vtkTransform.h>
#include <vtkTransformPolyDataFilter.h>



Transform::Transform(){}

// void Transform::translate(vtkSmartPointer<vtkDataSet> dataset, std::vector<double> coords)
// {
//   auto translation = vtkSmartPointer<vtkTransform>::New();
//   translation->Translate(coords(1),coords(2),coords(3));

//   auto transformFilter = vtkSmartPointer<vtkTransformPolyDataFilter>::New();
//   transformFilter->SetInputConnection(dataset->GetOutputPort());
//   transformFilter->SetTransform(translation);
//   transformFilter->Update();

//   auto transformedMapper = vtkSmartPointer<vtkPolyDataMapper>::New();
//   transformedMapper->SetInputConnection(transformFilter->GetOutputPort());

//   auto transformedActor = vtkSmartPointer<vtkActor>::New();
//   transformedActor->SetMapper(transformedMapper);
//   transformedActor->GetProperty()->->EdgeVisibilityOn();

//   auto renderer = vtkSmartPointer<vtkRenderer>::New();
//   renderer->AddActor(transformedActor);
//   renderer->SetBackground(0,0,0);

//   auto renderWindow = vtkSmartPointer<vtkRenderWindow>::New();
//   renderWindow->AddRenderer(renderer);

//   auto interactor = vtkSmartPointer<vtkRenderWindowInteractor>::New();
//   interactor->SetRenderWindow(renderWindow);

//   renderWindow->Render();
//   interactor->Start();
// }