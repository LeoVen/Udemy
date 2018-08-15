# #
# array_gen.py
#
# Leonardo Vencovsky (https://github.com/LeoVen)
#
# 14/08/2018
#
# #
import numpy as np

# generating arrays

def main():
	
	# array of zeros
	Z = np.zeros(10)

	print(Z, end="\n\n")

	# 2d array of zeroes
	M = np.zeros((10, 10)) # A tuple containing each dimension

	print(M, end="\n\n")

	# 2d array of ones
	O = np.ones((10, 10))

	print(O, end="\n\n")

	# 2d array of random numbers
	R = np.random.random((10, 10))

	# this random function gives an uniform distribution between 0 and 1
	print(R, end="\n\n")

	# Gaussian distribution
	G = np.random.randn(10, 10) # each dimension is passed separately

	print(G, end="\n\n") # mean 0 and variance of 1

	print("\nCalculating statistics")

	print("\nMean      : ", end="")
	print(G.mean())
	print("\nVariance  : ", end="")
	print(G.var())


if __name__ == '__main__':
	main()