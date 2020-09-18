//
// Created by Nick Baughman on 8/29/20.
//

#include <iostream>
#include "../include/Perceptron.h"

double Perceptron::feedForward(const std::vector<int> &inputValues) const {
    assert(inputValues.size() == this->inputs.size());

    auto sum = 0.0;
    // loop over all synapses
    for (auto i = 0; i < inputValues.size(); i++) {
        auto inputConnection = this->inputs.at(i);
        auto inputValue = inputValues.at(i);
        inputConnection->setInput(inputValue);
        // loop over all input values
        sum += inputConnection->getInput() * inputConnection->weight;

    }
    return sum > 0 ? 1 : -1; //bias
}

Perceptron::Perceptron(int inputSize, double learningRate) : alpha(learningRate) {
    for (auto i = 0; i < inputSize; i++) {
        inputs.emplace_back(new Input());
    }
}

void Perceptron::backPropagate(double target, double output) const {
    for (auto input : this->inputs) {
//        auto error = (target - output);
//        auto weightedError  = this->alpha * error;
//        auto deltaWeight = (weightedError * input->getInput()) + input->getInput();

        auto deltaWeight = (this->alpha * (target - output)) * input->getInput();
        input->weight += deltaWeight;

//        std::cout << std::endl;
    }
}
