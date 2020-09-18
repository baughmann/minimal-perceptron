//
// Created by Nick Baughman on 8/29/20.
//

#ifndef SIMPLE_PERCEPTRON_PERCEPTRON_H
#define SIMPLE_PERCEPTRON_PERCEPTRON_H


#include <vector>
#include "Input.h"

class Perceptron {
public:
    // the learning rate
    double alpha;
    std::vector<Input*> inputs;

    Perceptron(int inputSize, double learningRate);

    double feedForward(const std::vector<int>& input) const;

    void backPropagate(double target, double output) const;

};


#endif //SIMPLE_PERCEPTRON_PERCEPTRON_H
