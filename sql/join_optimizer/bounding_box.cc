//
// Created by leag on 19.02.24.
//
#include "sql/join_optimizer/bounding_box.h"
#include <type_traits>

double BoundingBox::incremental_step = 0.15;

double BoundingBox::GetUpperBound(const double estimate, RiskLevel risk_level) {
  return estimate * (1 + incremental_step * static_cast<std::underlying_type_t<RiskLevel>>(risk_level));
}
