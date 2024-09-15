#ifndef FUZZY_CONTROLLER_H
#define FUZZY_CONTROLLER_H

#include <vector>
#include "FuzzyRule.h"

class FuzzyController
{
private:
  std::vector<FuzzyRule> rules;

public:
  // Add a new fuzzy rule to the system
  void addRule(FuzzySet *ant1, FuzzySet *ant2, FuzzySet *cons);

  // Defuzzification using Centroid Method
  double defuzzifyCentroid(double input1, double input2, double minRange, double maxRange, int resolution = 100);

  // Defuzzification using Weighted Average Method
  double defuzzifyWeightedAverage(double input1, double input2);
};

#endif // FUZZY_CONTROLLER_H
