# #
# histogram.py
#
# Leonardo Vencovsky (https://github.com/LeoVen)
#
# 21/08/2018
#
# #

import matplotlib.pyplot as plt
import numpy as np
import pandas as pd

# Working with plt.hist()
# Using data_1d.csv

def main():
	
	# Loading data

	df = pd.read_csv('data/data_1d.csv', header=None).values

	# Row 0 goes to x and row 1 goes to y
	x = df[:,0]
	y = df[:,1]

	plt.hist(x)

	plt.show()

	R = np.random.random(10000)

	# Uniform distribution
	# bins = how many buckets
	plt.hist(R, bins=20, normed=1, ec='black')

	plt.show()


if __name__ == '__main__':
	main()