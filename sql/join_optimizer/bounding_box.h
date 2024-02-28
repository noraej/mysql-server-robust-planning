//
// Created by leag on 19.02.24.
//

#ifndef BOUNDING_BOX_H
#define BOUNDING_BOX_H

#include <tuple>

enum class RiskLevel;

class BoundingBox {
public:
  static double incremental_step;
  static double decremental_step;
  static double alpha;
  static double beta;
  static double gamma;

  static double GetUpperBound(double estimate, RiskLevel risk_level);
  static double GetLowerBound(double estimate, RiskLevel risk_level);
  static std::tuple<double, double, double> GetBoundingBox(double estimate, RiskLevel risk_level);
  static double ComputeCost(double lower_cost, double estimated_cost, double upper_cost);
  static double GetNewCost(double estimate, RiskLevel risk_level);
  static double GetNewEstimate(double estimate, RiskLevel risk_level);
};

enum class RiskLevel {
  Low = 0,
  Medium = 1,
  MediumHigh = 2,
  High = 3
};

#endif //BOUNDING_BOX_H