#include <memory>

#include "viewer.hpp"
#include "options.hpp"

#include <vtkSmartPointer.h>
#include <vtkActor.h>
#include <vtkDataSetMapper.h>
#include <vtkRenderWindow.h>
#include <vtkRenderWindowInteractor.h>
#include <vtkRenderer.h>
#include <vtkProperty.h>
#include <vtkDataSet.h>

Viewer::Viewer(){}

void Viewer::view(vtkSmartPointer<vtkDataSet> dataset)
{

  auto mapper = vtkSmartPointer<vtkDataSetMapper>::New();
  mapper->SetInputData(dataset);

  auto actor = vtkSmartPointer<vtkActor>::New();
  actor->SetMapper(mapper);
  actor->GetProperty()->EdgeVisibilityOn();
  // actor->SetBackfaceProperty(backProp);
  // actor->GetProperty()->SetDiffuseColor(colors->GetColor3d("Tomato").GetData());
  // actor->GetProperty()->SetSpecular(.3);
  // actor->GetProperty()->SetSpecularPower(30);

  auto renderer = vtkSmartPointer<vtkRenderer>::New();
  renderer->AddActor(actor);
  renderer->SetBackground(0,0,0);

  auto renderWindow = vtkSmartPointer<vtkRenderWindow>::New();
  renderWindow->AddRenderer(renderer);

  auto interactor = vtkSmartPointer<vtkRenderWindowInteractor>::New();
  interactor->SetRenderWindow(renderWindow);

  renderWindow->Render();
  interactor->Start();
}
