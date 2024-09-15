#include <iostream>
#include "include/FuzzyLogicController.hpp"

int main()
{
  // Define input and output fuzzy sets
  FuzzySet lowInput1(0.0, 0.0, 5.0);
  FuzzySet mediumInput1(2.5, 5.0, 7.5);
  FuzzySet highInput1(5.0, 10.0, 10.0);

  FuzzySet lowInput2(0.0, 0.0, 5.0);
  FuzzySet mediumInput2(2.5, 5.0, 7.5);
  FuzzySet highInput2(5.0, 10.0, 10.0);

  FuzzySet lowOutput(0.0, 0.0, 5.0);
  FuzzySet mediumOutput(2.5, 5.0, 7.5);
  FuzzySet highOutput(5.0, 10.0, 10.0);

  // Create the fuzzy controller
  FuzzyController controller;

  // Add rules
  controller.addRule(&lowInput1, &lowInput2, &lowOutput);
  controller.addRule(&mediumInput1, &mediumInput2, &mediumOutput);
  controller.addRule(&highInput1, &highInput2, &highOutput);

  // Inputs
  double input1 = 6.0;
  double input2 = 7.0;

  // Defuzzification using Centroid method
  double outputCentroid = controller.defuzzifyCentroid(input1, input2, 0.0, 10.0);
  std::cout << "Defuzzified Output (Centroid Method): " << outputCentroid << std::endl;

  // Defuzzification using Weighted Average method
  double outputWeightedAvg = controller.defuzzifyWeightedAverage(input1, input2);
  std::cout << "Defuzzified Output (Weighted Average Method): " << outputWeightedAvg << std::endl;

  return 0;
}
