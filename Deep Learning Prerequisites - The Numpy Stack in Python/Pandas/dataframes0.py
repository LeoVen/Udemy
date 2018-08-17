# #
# dataframes0.py
#
# Leonardo Vencovsky (https://github.com/LeoVen)
#
# 17/08/2018
#
# #
import numpy as np
import pandas as pd

# Working with dataframes
# Using data_2d.csv

def main():
	
	X = pd.read_csv("data/data_2d.csv", header=None)

	print(type(X))
	print(X.info())

	print(X.head())
	print(X.head(20)) # 20 first lines

	# Transform dataframe into a matrix
	M = X.values
	print(type(M))
	print(M.shape)

	# Note:
	# Numpy  : M[0] -> 0th Row
	# Pandas : X[0] -> Column that has a name of 0
	print(M[0])
	print(X[0])
	print(type(X[0]))

	# How to get the rows in pandas
	print(X.iloc[0])
	print(type(X.iloc[0]))

	# All rows where column of name 0 is less than 5
	print(X[X[0] < 5])


if __name__ == '__main__':
	main()