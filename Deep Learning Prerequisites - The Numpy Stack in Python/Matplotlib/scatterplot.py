# #
# scatterplot.py
#
# Leonardo Vencovsky (https://github.com/LeoVen)
#
# 21/08/2018
#
# #

import matplotlib.pyplot as plt
import numpy as np
import pandas as pd

# Working with plt.scatter()
# Using data_1d.csv

def main():
	
	# Loading data

	df = pd.read_csv('data/data_1d.csv', header=None).values

	# Row 0 goes to x and row 1 goes to y
	x = df[:,0]
	y = df[:,1]

	plt.scatter(x, y)

	# this is the corresponding line
	x_line = np.linspace(0, 100, 100)
	y_line = 2 * x_line + 1

	plt.plot(x_line, y_line, 'r-')

	plt.show()


if __name__ == '__main__':
	main()