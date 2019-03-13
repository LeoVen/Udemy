# Artificial Neural Networks

## Theory

* The Neuron
* The Activation Function
* How Neural Networks work
* How Neural Networks learn
* Gradient Descent
* Stochastic Gradient Descent
* Backpropagation

## Training Steps

1. Randomly initialise the weights to small numbers close to 0, but not 0
2. Input the first observation of the dataset in the input layer, each feature in one input node
3. Forward-Propagation: from left to right, the neurons are activated in a way that the impact of each neuron's activation is limited by the weights. Propagate the activations until getting the predicted result `y`
4. Compare the predicted result to the actual result. Measure the generated error
5. Back-Propagation: from right to left, the error is back-propagated. Update the weigths according to how much they are responsible for the error. The learning rate decides by how much we update the weights
6. Repeat steps 1 to 5 and update the weigths after each observation (Reinforcement Learning). Or repeat steps 1 to 5 but update the weigths only after a batch of observations (Batch Learning)
7. When the whole training set passed through the ANN, that makes an epoch. Redo more epochs