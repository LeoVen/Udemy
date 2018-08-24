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
from scipy.stats import multivariate_normal as mvn

def main():
	
	# Covariance matrix
	cov = np.array([[1, 0.8], [0.8, 3]])

	mu = np.array([0, 2])

	r = mvn.rvs(mean=mu, cov=cov, size=1000)

	# can also use numpy
	# r = np.random.multivariate_normal(mean=mu, cov=cov, size=1000)

	plt.scatter(r[:,0], r[:,1])

	plt.axis('equal')

	plt.show()


if __name__ == '__main__':
	main()