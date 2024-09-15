#include "FuzzyController.h"
#include <algorithm> // For std::max

// Add a rule to the fuzzy controller
void FuzzyController::addRule(FuzzySet *ant1, FuzzySet *ant2, FuzzySet *cons)
{
  rules.push_back(FuzzyRule(ant1, ant2, cons));
}

// Defuzzification using Centroid Method
double FuzzyController::defuzzifyCentroid(double input1, double input2, double minRange, double maxRange, int resolution)
{
  double numerator = 0.0, denominator = 0.0;

  for (double x = minRange; x <= maxRange; x += (maxRange - minRange) / resolution)
  {
    double outputMembership = 0.0;
    for (const auto &rule : rules)
    {
      outputMembership = std::max(outputMembership, std::min(rule.evaluate(input1, input2), rule.consequent->membership(x)));
    }
    numerator += x * outputMembership;
    denominator += outputMembership;
  }

  return (denominator == 0.0) ? 0.0 : numerator / denominator;
}

// Defuzzification using Weighted Average Method
double FuzzyController::defuzzifyWeightedAverage(double input1, double input2)
{
  double numerator = 0.0, denominator = 0.0;

  for (const auto &rule : rules)
  {
    double ruleStrength = rule.evaluate(input1, input2);
    double ruleCentroid = (rule.consequent->a + rule.consequent->b + rule.consequent->c) / 3.0;
    numerator += ruleStrength * ruleCentroid;
    denominator += ruleStrength;
  }

  return (denominator == 0.0) ? 0.0 : numerator / denominator;
}
