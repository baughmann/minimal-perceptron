# Minimal C++ Perceptron

### Purpose
This was my first foray into machine learning. As such, I desired to make the simplest version of the simplest ML concept that I could think of.

### Function
The Perceptron learns to be an [XOR gate](https://en.wikipedia.org/wiki/XOR_gate), that is:

| X1 | X2 | Output |
|---|---|---|
| 0 | 0 | 0 |
| 0 | 1 | 1 |
| 1 | 0 | 1 |
| 1 | 1 | 0 |

The number of iteratorations is directly proportional to the `length` parameter that is passed to the `generateTestData()` function. 
I have set the default to 10,000 iterations. This roughly equates to an accuracy of `0.0007 = 0` and `0.9989 = 1`.