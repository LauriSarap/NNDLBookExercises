#include <iostream>
#include "Perceptron.h"
#include <numeric>

Perceptron::Perceptron(size_t input_size, double initial_weights, double learning_rate) : weights(input_size + 1, initial_weights)
{
    this->input_size = input_size;
    this->learning_rate = learning_rate;
}

double Perceptron::ForwardPropagation(const std::vector<double>& x)
{
    std::vector<double> inputs_with_bias = x;
    inputs_with_bias.push_back(1.0);
    double weighted_sum = 0.0;
    for (size_t i = 0; i < weights.size(); ++i)
    {
        inputs_with_bias[i] *= weights[i];
        weighted_sum += inputs_with_bias[i];
    }
    double y_hat = ActivationFunction(weighted_sum);
    return y_hat;
}

void Perceptron::Train(const std::vector<double>& x_train, const double& y_train)
{
    double y_hat = ForwardPropagation(x_train);

    // Backward prop
    double error = y_train - y_hat;
    for (size_t i = 0; i < weights.size() - 1; ++i)
    {
        weights[i] += learning_rate * error * x_train[i];
    }
    weights.back() += learning_rate * error;
}

double Perceptron::ActivationFunction(double x)
{
    return x > 0 ? 1 : 0;
}
