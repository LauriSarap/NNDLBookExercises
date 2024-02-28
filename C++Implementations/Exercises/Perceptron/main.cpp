#include <iostream>
#include <string>

#include "Perceptron.h"

int main()
{
    Perceptron perceptron(2, 0, 0.01);

    std::vector<std::vector<double>> inputs = {{0, 0}, {0, 1}, {1, 0}, {1, 1}};
    std::vector<double> outputs = {0, 0, 0, 1};

    for (int i = 0; i < 100; ++i)
    { 
        for (size_t j = 0; j < inputs.size(); ++j)
        {
            perceptron.Train(inputs[j], outputs[j]);
        }
    }
    
    for (const auto& input : inputs) {
        std::cout << "Input: " << input[0] << ", " << input[1]
                  << " Prediction: " << perceptron.ForwardPropagation(input) << std::endl;
    }
    
    while (true)
    {
       
    }
    return 0;
}
