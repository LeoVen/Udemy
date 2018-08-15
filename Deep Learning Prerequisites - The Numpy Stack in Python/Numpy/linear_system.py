# #
# linear_system.py
#
# Leonardo Vencovsky (https://github.com/LeoVen)
#
# 14/08/2018
#
# #
import numpy as np

# Solving a linear system

def main():
	
	# Problem  : A * x = B
	# Solution : Inv(A) * A * x = Inv(A) * B

	A = np.array([ [1, 2], [3, 4] ])
	B = np.array([1, 2])

	print("Not very accurate")
	print(np.linalg.inv(A).dot(B), end="\n\n")

	print("Much faster and accurate")
	print(np.linalg.solve(A, B), end="\n\n")



if __name__ == '__main__':
	main()