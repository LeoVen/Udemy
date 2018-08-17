# #
# join.py
#
# Leonardo Vencovsky (https://github.com/LeoVen)
#
# 17/08/2018
#
# #
import numpy as np
import pandas as pd

# Joining two dataframes
# Using table1.csv and table2.csv

def main():
	
	T1 = pd.read_csv("data/table1.csv")
	T2 = pd.read_csv("data/table2.csv")

	# Joining by user_id column
	# Using pd.merge()

	M = pd.merge(T1, T2, on="user_id")

	print(M, end="\n\n")

	# Can also be done as:
	M = T1.merge(T2, on="user_id")

	print(M)


if __name__ == '__main__':
	main()