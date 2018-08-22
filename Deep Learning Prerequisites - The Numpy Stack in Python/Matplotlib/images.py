# #
# images.py
#
# Leonardo Vencovsky (https://github.com/LeoVen)
#
# 21/08/2018
#
# #

import matplotlib.pyplot as plt
import numpy as np
import pandas as pd

# Working with plt.imshow()
# Using train.csv from https://www.kaggle.com/c/digit-recognizer/

def main():
	
	# Loading data

	df = pd.read_csv('data/train.csv').values

	image = df[0, 1:]

	im = image.reshape(28, 28)

	plt.imshow(im)

	# You can also plot it as black and white
	# plt.imshow(im, cmap='gray')

	# Or as white and black
	# plt.imshow(255 - im, cmap='gray')

	plt.show()


if __name__ == '__main__':
	main()