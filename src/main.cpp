#include <iostream>
#include "../include/Perceptron.h"
#include <cstdlib>
#include <ctime>

std::vector<std::vector<int>*>* generateTestData(int length) {
    // seed random
    srand(time(NULL));
    // create a list of input lists
    auto testData = new std::vector<std::vector<int>*>();
    // fill each list item
    for(auto i = 0; i < length; i++) {
        int x1 = rand() % 2;
        int x2 = rand() % 2;
        auto target = x1 == x2 ? 1 : 0;

        testData->push_back(new std::vector<int>{x1, x2, target});
    }

    return testData;
}

int main() {
    // generate test data
    auto inputs = generateTestData(1000);
    // instantiate weights
    std::vector<double> weights({0.0, 0.0, 0.0});
    // learning rate
    auto eta = 0.1;
    // a list of resulting calculations
    std::vector<std::vector<int>> outputs(inputs->size());
    // calculate the estimates
    for (auto input : *inputs) {
        // calculate the prediction
        auto sum = 0.0;
        for(auto j = 0; j < weights.size(); j++) {
            // get the values of the input x the weight of the synapse
            sum += weights.at(j)
                    * input->at(j);
        }
        // activate the result
        sum = tanh(sum);

        // measure the errors and adjust the weights
        for (auto j = 0; j < weights.size(); j++) {
            auto deltaWeight = (eta*(input->back() - sum))*input->at(j);
            weights.at(j) += deltaWeight;
//            std::cout << "result was off by " << input.back() - sum << " so i'm modifying the weight of input " << j << " by " << deltaWeight << std::endl;
        }


        std::cout << "Guess was " << sum << " and expected was " << input->at(2) << std::endl;
//        outputs.push_back({input.at(0), input.at(1), sum})
    }

//    for (auto output : outputs) {
//        std::cout << output.at(0) << " " << output.at(1) << " = " << output.at(2)
//    }
}
