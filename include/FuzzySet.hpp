#ifndef FUZZY_SET_H
#define FUZZY_SET_H

class FuzzySet
{
public:
  double a, b, c; // Triangle parameters

  FuzzySet(double a, double b, double c);

  // Membership function for triangular set
  double membership(double x) const;
};

#endif // FUZZY_SET_H
