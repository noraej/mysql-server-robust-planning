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

  static double GetUpperBound(double estimate, RiskLevel risk_level);
};

enum class RiskLevel {
  Low = 0,
  Medium = 1,
  MediumHigh = 2,
  High = 3
};

#endif //BOUNDING_BOX_H
