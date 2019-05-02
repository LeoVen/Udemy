# Regression

## Linear Regression

* Simple Linear Regression
    * `y = b0 + b1*x1`
* Multiple Linear Regression
    * `y = b0 + b1*x1 + b2*x2 + ... + bn*xn`
* Polynomial Linear Regression
    * `y = b0 + b1*x1^2 + b2*x1^3 + ... + bn*x1^n`

### Assumptions of a Multiple Linear Regression

* Linearity
    * There must be a linear relationship between the outcome variable and the independent variables.
* Homoscedasticity
    * This assumption states that the variance of error terms are similar across the values of the independent variables.
* Multivariate normality
    * Multiple regression assumes that the residuals are normally distributed.
* Independence of errors
    * Residuals must not be correlated.
* Lack of multicollinearity
    * Multiple regression assumes that the independent variables are not highly correlated with each other.

### Methods of building models

1. All-in
2. Backward Elimination
3. Forward Selection
4. Bidirectional Elimination
5. Score Comparison

Stepwise Regression refers to numbers 2, 3 and 4.

## Support Vector Machine

It is a classification technique. It calculates the distance between the support vectors and the hyperplane are as far as possible (maximizing the margin).

* Pros
    * Good at dealing with high dimensional data
    * Works well on small data sets
* Cons
    * Picking the right kernel and parameters can be computationally intensive

### Parameters

* kernel type
* C
* Gamma

### Topics

* Higher dimensions
* C Parameter
    * How much to penalize misclassified points (defaults to `1.0`)
    * Low `C`: Prioritize simplicity
    * High `C`: Prioritize making few mistakes
* Multiple classes
    * OVR: One vs Rest
        * Pros: Fewer classifications
        * Cons: Classes may be imbalanced
    * OVO: One vs One
        * Pros: Less sensitive to imbalance
        * Cons: More classifications
* The Kernel Trick
* Gamma parameter
    * Small gamma: Less complexity
    * Large gamma: More complexity
* Popular Kernels
    * Fisher kernel
    * Graph kernels
    * Kernel smoother
    * Polynomial kernel
    * Radial basis function kernel (RBF)
    * String kernels

* A type of Support Vector Machine
    * Support linear and nonlinear regression referred as SVR
