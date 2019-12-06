#pragma once

#include <vtkSmartPointer.h>

class vtkDataSet;

class Viewer
{
public:
  Viewer(void);
  ~Viewer(void){};

  void view(vtkSmartPointer<vtkDataSet> dataset);
};
