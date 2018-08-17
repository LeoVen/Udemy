# #
# dataframes1.py
#
# Leonardo Vencovsky (https://github.com/LeoVen)
#
# 17/08/2018
#
# #
import numpy as np
import pandas as pd

# Working with dataframes
# Using international-airline-passengers.csv

def main():
	
	# Pandas by default reads a header
	# Default engine is C but skipfooter only works with python engine
	df = pd.read_csv("data/international-airline-passengers.csv", engine="python", skipfooter=3)

	print(df)

	# Dataframe columns
	print(df.columns)

	# Changing column names
	df.columns = ["month", "passengers"]

	print(df.columns)

	print(df["passengers"])
	# If a column name is a string without spaces
	# df.passengers

	# Assigning a column with data
	df["hundreds"] = 100 # A column of name hundreds where each row is 100
	print(df.head())

	# See apply function


if __name__ == '__main__':
	main()