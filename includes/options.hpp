#pragma once

#include <memory>

#include "cpptoml.h"


class OptionsParser
{
public:
  OptionsParser(const std::string&);
  ~OptionsParser(void) {}

  // TODO: modifier le type de retour en cohérence
  // avec la structure de données renvoyée.
  void parse(void); // retour des données

private:
  std::string m_file_name;
  std::shared_ptr<cpptoml::table> m_data;
};
