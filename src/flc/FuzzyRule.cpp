#include "FuzzyRule.h"
#include <algorithm> // For std::min

// Constructor
FuzzyRule::FuzzyRule(FuzzySet *ant1, FuzzySet *ant2, FuzzySet *cons)
    : antecedent1(ant1), antecedent2(ant2), consequent(cons) {}

// Rule evaluation
double FuzzyRule::evaluate(double input1, double input2) const
{
  return std::min(antecedent1->membership(input1), antecedent2->membership(input2));
}
