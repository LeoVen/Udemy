# #
# arrays.py
#
# Leonardo Vencovsky (https://github.com/LeoVen)
#
# 14/08/2018
#
# #
import numpy as np

# Comparing lists and numpy arrays

def main():
	
	
	print("\nPython list:")
	
	l = [e for e in range(5)]

	print(l)

	l += [5]

	print(l)

	print(2 * l)

	# you can't power a list
	# print(l ** 2)

	# numpy arrays are element-wise 
	print("\nNumpy array:")

	A = np.array([1, 2, 3])

	print(A)

	print(A + A)

	print(2 * A)

	print(A ** 2)

	print(A ** (1/2))

	print(np.log(A))

	print(np.exp(A))



if __name__ == '__main__':
	main()