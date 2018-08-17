# #
# apply.py
#
# Leonardo Vencovsky (https://github.com/LeoVen)
#
# 17/08/2018
#
# #
from datetime import datetime
import numpy as np
import pandas as pd

# Working with dataframes
# Using international-airline-passengers.csv

# Valid function for apply() argument
# Not used (see lambda function)
def operation(row):
	return row["x1"] * row["x2"]


def main():
	
	# Pandas by default reads a header
	# Default engine is C but skipfooter only works with python engine
	df = pd.read_csv("data/international-airline-passengers.csv", engine="python", skipfooter=3)
	
	# Changing column names
	df.columns = ["month", "passengers"]

	# Assigning a column with data
	df["ones"] = 1 # A column of name hundreds where each row is 1

	# ["month", "passengers", "ones"]

	# Using datetime.strptime()
	df["datetime"] = df.apply(lambda row: datetime.strptime(row["month"], "%Y-%m"), axis=1)

	print(df.head())
	print(df.info())



if __name__ == '__main__':
	main()