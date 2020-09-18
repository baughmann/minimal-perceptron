#include <iostream>
#include <cstdlib>
#include <ctime>
#include <vector>

std::vector<std::vector<int>*>* generateTestData(int length) {
    // seed random
    srand(time(NULL));
    // create a list of input lists
    auto testData = new std::vector<std::vector<int>*>();
    // fill each list item
    for(auto i = 0; i < length; i++) {
        int x1 = rand() % 2;
        int x2 = rand() % 2;
        auto target = x1 != x2 ? 1 : 0;

        testData->push_back(new std::vector<int>{x1, x2, target});
    }

    return testData;
}

int main() {
    // generate test data
    auto inputs = generateTestData(10000);
    // instantiate weights
    std::vector<double> weights({0.0, 0.0, 0.0});
    // learning rate
    auto eta = 0.1;
    // a list of resulting calculations
    std::vector<std::tuple<int, double>> outputs(inputs->size());
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
        }

        // add expected result and the guessed value to the list of outputs
        outputs.push_back({input->at(2), sum});
    }

    // iterate over the outputs and log them to the console
    for (auto [expected, guess] : outputs) {
        std::cout << "Guess was " << guess << " and expected was " << expected << std::endl;
    }
}
