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

### Reuse
If you decide to copy some of this stuff for your own projects, just be aware of the following:
- The `inputs` is a vector pointer to vector pointers. I decided to put that vector on the stack since it's size could be extremely large.
- The activaction function is currently `tanh` (i.e. hyperbolic tangent) which is not at all appropriate for an XOR gate. However, I desired to see the improvement in accuracy progressing with each iteration.