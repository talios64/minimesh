#pragma once

#include <vtkSmartPointer.h>


class QualityChecker
{
public:
  QualityChecker(void);
  ~QualityChecker(void) {}

  void Quality_Analysis(vtkSmartPointer<vtkDataSet> dataset);

private:
  // TODO
};
