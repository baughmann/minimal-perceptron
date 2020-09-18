//
// Created by Nick Baughman on 8/29/20.
//

#include <cstdlib>
#include <iostream>
#include "../include/Input.h"

Input::Input() {
//    this->weight = randomWeight();
}

double Input::randomWeight() {
    static bool isSecond = false;
    auto output = isSecond ? 0.5 : -0.5;
    isSecond = true;
    return output;
}
