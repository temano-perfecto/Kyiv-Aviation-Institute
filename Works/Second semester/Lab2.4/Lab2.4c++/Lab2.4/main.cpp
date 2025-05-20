#include <iostream>
#include <vector>
#include "ExpressionCalculator.h"

int main() {
    std::vector<ExpressionCalculator> calculators = {
        ExpressionCalculator(1, 2, 3),
        ExpressionCalculator(0, 1, 0),  
        ExpressionCalculator(2, 3, -1), 
        ExpressionCalculator(0, 1, 1)   
    };

    for (size_t i = 0; i < calculators.size(); ++i) {
        std::cout << "Calculating for object " << i + 1 << " (a=" << calculators[i].getA()
            << ", c=" << calculators[i].getC() << ", d=" << calculators[i].getD() << "): ";

        try {
            double result = calculators[i].calculate();
            std::cout << "Result = " << result << std::endl;
        }
        catch (const std::invalid_argument& e) {
            std::cout << "Error: " << e.what() << std::endl;
        }
        catch (...) {
            std::cout << "Unknown error occurred" << std::endl;
        }
    }

    return 0;
}