#include "FuzzySet.h"

// Constructor
FuzzySet::FuzzySet(double a, double b, double c) : a(a), b(b), c(c) {}

// Triangular membership function
double FuzzySet::membership(double x) const
{
  if (x <= a || x >= c)
    return 0.0;
  else if (x == b)
    return 1.0;
  else if (x < b)
    return (x - a) / (b - a);
  else
    return (c - x) / (c - b);
}
