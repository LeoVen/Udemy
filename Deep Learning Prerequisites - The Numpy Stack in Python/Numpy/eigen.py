# #
# eigen.py
#
# Leonardo Vencovsky (https://github.com/LeoVen)
#
# 14/08/2018
#
# #
import numpy as np

# Covariance, Eigen Values and Eigen Vectors


def main():

	# Variance:
	# "How far a set of (random) numbers are spread out from their average value"
	#
	# Let x and y be two samples of data
	#
	# E[x] = Expected value for x (mean or average of the sample)
	# Var(x) = Variance of a sample x
	# Cov(x, y) = Covariance of sample x and y
	#
	# Cov(x, y) = E[(x - E[x]) * (y - E[y])]
	# Cov(x, y) = E[x * y] - (E[y] * E[x])
	#
	# Where each part is approximated to:
	# E[x * y] ~ mean(x * y)
	# E[y] * E[x] ~ mean(y)
	#
	# Putting all together
	# ~ ( mean(x * y) - mean(x) * mean(y) )
	#
	# Note
	# Cov(x, x) = Var(x)

	x = np.random.randn(100, 3)

	# Wrong
	covx = np.cov(x)
	print(covx.shape, end="\n\n")

	# Need to transpose it first
	covx = np.cov(x.T)
	print(covx, end="\n\n")

	# Eigen values, vectors
	# np.linalg.eig()

	# Eigen values, vectors for symmetric and Hermitian matrices
	# np.linalg.eigh()

	# 1st tuple: eigen values
	# 2nd tuple: eigen vectors
	print(np.linalg.eigh(covx), end="\n\n")
	print(np.linalg.eig(covx), end="\n\n")  # Should result in the same thing



if __name__ == '__main__':
	main()