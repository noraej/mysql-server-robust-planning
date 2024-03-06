//
// Created by leag on 06.03.24.
//
#include "uncertain_choice_counter.h"
#include <ios>
#include <unordered_map>
#include <string>
#include <fstream>

std::unordered_map<int, int> UncertainChoiceCounter::counter;
int UncertainChoiceCounter::currentQuery;

void ::UncertainChoiceCounter::AddNewCounterForQuery(){
  currentQuery += 1;
  counter.insert({currentQuery, 0});
}

void ::UncertainChoiceCounter::IncreaseCounter() {
  auto pair = counter.find(currentQuery);
  if(pair != counter.end()) {
    pair->second = pair->second + 1;
  }
}

void ::UncertainChoiceCounter::PrintCountInformation() {
  std::string plansAndChoices;
  for (const auto & pair: counter) {
    plansAndChoices += "[";
    plansAndChoices += std::to_string(pair.first);
    plansAndChoices += ", ";
    plansAndChoices += std::to_string(pair.second);
    plansAndChoices += "], ";
  }
  plansAndChoices += "\n";

  std::ofstream outputfile("/home/leag/MySQL/mysql-server-robust-planning/cmake-build-release/mysql-test/var/log/uncertain_choices_count.txt", std::ios::out | std::ios::binary);
  outputfile << plansAndChoices;
  outputfile.close();
}