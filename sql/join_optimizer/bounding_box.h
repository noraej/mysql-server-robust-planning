//
// Created by leag on 19.02.24.
//

#ifndef BOUNDING_BOX_H
#define BOUNDING_BOX_H

#include "risk_level.h"
#include <tuple>

class BoundingBox {
public:
  static double incremental_step;
  static double decremental_step;
  static double alpha;
  static double beta;
  static double gamma;

  static double GetUpperBound(double estimate, RiskLevel risk_level);
  static double GetLowerBound(double estimate, RiskLevel risk_level);
  static double ComputeCost(double lower_cost, double estimated_cost, double upper_cost);
  static double GetNewCost(double estimate, RiskLevel risk_level);
};

#endif //BOUNDING_BOX_H