# #
# linechart.py
#
# Leonardo Vencovsky (https://github.com/LeoVen)
#
# 21/08/2018
#
# #

import matplotlib.pyplot as plt
import numpy as np

# Working with plt.plot()

def main():
	
	x = np.linspace(0, 10, 40)
	y = np.sin(x)

	plt.xlabel("Here is the X label")
	plt.ylabel("Here is the Y label")
	plt.title("Here is the Title")

	plt.plot(x, y)

	plt.show()


if __name__ == '__main__':
	main()