#pragma once
#include <vector>

class Perceptron
{
public:
    Perceptron(size_t input_size, double initial_weights, double learning_rate);
    
    void Train(const std::vector<double>& x_train, const double& y_train);
    double ForwardPropagation(const std::vector<double>& x);

private:
    size_t input_size;
    std::vector<double> weights;
    double learning_rate;
    double ActivationFunction(double x);
};
