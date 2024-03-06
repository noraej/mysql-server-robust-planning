//
// Created by leag on 06.03.24.
//

#ifndef UNCERTAIN_CHOICE_COUNTER_H
#define UNCERTAIN_CHOICE_COUNTER_H
#include <unordered_map>

class UncertainChoiceCounter {
public:
  static std::unordered_map<int, int> counter;
  static int currentQuery;
  static void AddNewCounterForQuery();
  static void IncreaseCounter();
  static void PrintCountInformation();

  UncertainChoiceCounter() = delete;
};

#endif //UNCERTAIN_CHOICE_COUNTER_H
