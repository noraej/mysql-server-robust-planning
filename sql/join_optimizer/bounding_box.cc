//
// Created by leag on 19.02.24.
//
#include "sql/join_optimizer/bounding_box.h"
#include <type_traits>

double BoundingBox::incremental_step = 0.1;
double BoundingBox::decremental_step = 0.05;
double BoundingBox::alpha = 0.7;
double BoundingBox::beta = 0.2;
double BoundingBox::gamma = 0.1;

double BoundingBox::GetUpperBound(const double estimate, RiskLevel risk_level) {
  return estimate * (1 + incremental_step * static_cast<std::underlying_type_t<RiskLevel>>(risk_level));
}

double BoundingBox::GetLowerBound(const double estimate, RiskLevel risk_level) {
  return estimate * (1 - decremental_step * static_cast<std::underlying_type_t<RiskLevel>>(risk_level));
}
