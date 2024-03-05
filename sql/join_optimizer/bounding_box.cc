//
// Created by leag on 19.02.24.
//
#include "sql/join_optimizer/bounding_box.h"
#include <type_traits>
#include "risk_level.h"

double BoundingBox::incremental_step = 0.2;
double BoundingBox::decremental_step = 0.1;
double BoundingBox::alpha = 0.5;
double BoundingBox::beta = 0.4;
double BoundingBox::gamma = 0.1;

double BoundingBox::GetUpperBound(const double estimate, RiskLevel risk_level) {
  return estimate * (1 + incremental_step * static_cast<std::underlying_type_t<RiskLevel>>(risk_level));
}

double BoundingBox::GetLowerBound(const double estimate, RiskLevel risk_level) {
  return estimate * (1 - decremental_step *
                             static_cast<std::underlying_type_t<RiskLevel>>(
                                 risk_level));
}

double BoundingBox::ComputeCost(const double lower_cost, const double estimated_cost, const double upper_cost) {
  return (alpha * estimated_cost) + (beta * upper_cost) + (gamma * lower_cost);
}

double BoundingBox::GetNewCost(const double estimate, const RiskLevel risk_level) {
  const double lower_cost = GetLowerBound(estimate, risk_level);
  const double upper_cost = GetUpperBound(estimate, risk_level);
  return ComputeCost(lower_cost, estimate, upper_cost);
}