#ifndef FUZZY_RULE_H
#define FUZZY_RULE_H

#include "FuzzySet.h"

class FuzzyRule
{
public:
  FuzzySet *antecedent1; // First input fuzzy set
  FuzzySet *antecedent2; // Second input fuzzy set
  FuzzySet *consequent;  // Output fuzzy set

  FuzzyRule(FuzzySet *ant1, FuzzySet *ant2, FuzzySet *cons);

  // Evaluate rule strength based on inputs
  double evaluate(double input1, double input2) const;
};

#endif // FUZZY_RULE_H
