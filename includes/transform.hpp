#pragma once

enum TransformType
{
    TRANSFROM_MERGE, TRANSFORM_TRANSLATION
};

struct Params
{
  virtual ~Params(void) = default;

  // TODO
};

struct MergeParams : public Params
{
  // TODO
};

struct TranslationParams : public Params
{
  // TODO
};

class Transform
{
public:
  Transform(void);
  ~Transform(void) {}

  // void translate(vtkSmartPointer<vtkDataSet> dataset, std::vector<double> coords);
};
