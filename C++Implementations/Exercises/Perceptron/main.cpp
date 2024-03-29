#include <iostream>
#include <string>

#include "Perceptron.h"

int main()
{
    const int epochs = 100;
    const double learning_rate = 0.1;
    
    Perceptron perceptron(2, 0, learning_rate);

    std::vector<std::vector<double>> inputs = {{-3, 2}, {-2, 4}, {-1, 6}, {1, 6}, {2, 4}, {3, 2}};
    std::vector<double> outputs = {0, 0, 1, 1, 0, 0};

    for (int i = 0; i < epochs; ++i)
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
