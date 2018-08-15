# #
# matrices.py
#
# Leonardo Vencovsky (https://github.com/LeoVen)
#
# 14/08/2018
#
# #
import numpy as np

# Matrices vs 2d arrays

def main():
	
	# First index is the row, second index is the column
	M = np.array([ [1, 2], [3, 4] ])

	# python list
	L = [ [1, 2], [3, 4] ]

	print("\nPython List")
	print(L)
	print(L[0])
	print(L[0][0])

	print("\nNumpy array")
	print(M)
	print(M[0])
	print(M[0][0])
	print(M[0, 0])

	m = np.matrix([ [1, 2], [3, 4] ])

	print("\nNumpy matrix")
	print(m)

	# Docs says we shouldn't use matrix, instead use array
	# Converting a matrix to an array
	m = np.array(m)

	print(m)

	print("\nTranspose")
	print(m.T)



if __name__ == '__main__':
	main()