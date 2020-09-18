//
// Created by Nick Baughman on 8/29/20.
//

#ifndef SIMPLE_PERCEPTRON_INPUT_H
#define SIMPLE_PERCEPTRON_INPUT_H


class Input {
private:
    int inputValue = 0;

    static double randomWeight();

public:
    double weight = 0;

    double getInput() { return this->inputValue; }

    void setInput(double next) { this->inputValue = next; }

    Input();
};


#endif //SIMPLE_PERCEPTRON_INPUT_H
