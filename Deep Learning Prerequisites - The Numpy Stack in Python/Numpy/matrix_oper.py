# #
# matrix_oper.py
#
# Leonardo Vencovsky (https://github.com/LeoVen)
#
# 14/08/2018
#
# #
import numpy as np

# Operations on matrices

def main():
	
	# Three matrices A, B and C
	# A * B = C

	# C(i, j) = summation(k = 1, to K)->[A(i, k) B(k, j)]

	A = np.array([ [1, 2], [3, 4] ])
	B = np.array([ [1, 2], [3, 4] ])

	print("Element by element multiplication")
	print(A * B, end="\n\n")

	print("Dot: matrix multiplication")
	print(A.dot(B), end="\n\n")

	print("Matrix inverse")
	A_inv = np.linalg.inv(A)
	print(A_inv, end="\n\n")

	print("A * A_inverse")
	print(A.dot(A_inv), end="\n\n")

	print("Determinant")
	print(np.linalg.det(A), end="\n\n")

	print("Diagonal")
	print(np.diag(A), end="\n\n")

	print("You can also make a matrix using only the diagonal")
	D = np.diag([1, 2, 3])
	print(D, end="\n\n")

	print(np.diag(np.ones(5)), end="\n\n")

	a = np.array([1, 2])
	b = np.array([3, 4])

	# The * operand is an element-wise product
	# The dot product is also called Inner Product

	print("Outer Product")
	print(np.outer(a, b), end="\n\n")

	print("Inner Product")
	print(np.inner(a, b), end="\n\n")

	print("np.inner == dot")
	print(np.inner(a, b) == a.dot(b), end="\n\n")

	# Matrix trace is the sum of the diagonals of the matrix
	print("Matrix trace")
	print(np.diag(A).sum())
	print(np.trace(A))

	
	

if __name__ == '__main__':
	main()