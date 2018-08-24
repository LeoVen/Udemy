# #
# sampling.py
#
# Leonardo Vencovsky (https://github.com/LeoVen)
#
# 24/08/2018
#
# #
import numpy as np
import matplotlib.pyplot as plt

def main():
	
	# Standard deviation 10 and mean 5
	r = 10 * np.random.randn(10000) + 5

	plt.hist(r, bins=100, ec='black')

	plt.show()

	# Circle
	r = np.random.randn(10000, 2)

	plt.scatter(r[:,0], r[:,1])

	plt.axis('equal')

	plt.show()

	# Elliptical
	r[:,1] = 5 * r[:,1] + 2

	plt.scatter(r[:,0], r[:,1])

	plt.axis('equal')

	plt.show()


if __name__ == '__main__':
	main()