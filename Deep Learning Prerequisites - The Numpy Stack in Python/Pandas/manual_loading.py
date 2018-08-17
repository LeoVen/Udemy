# #
# manual_loading.py
#
# Leonardo Vencovsky (https://github.com/LeoVen)
#
# 17/08/2018
#
# #
import numpy as np

# Manually loading a CSV file
# Using data_2d.csv

def main():

	X = []

	for line in open("data/data_2d.csv"):

		row = line.split(",")
		values = list(map(float, row))
		X.append(values)

	X = np.array(X)

	print(X)
	print(X.shape)



if __name__ == '__main__':
	main()