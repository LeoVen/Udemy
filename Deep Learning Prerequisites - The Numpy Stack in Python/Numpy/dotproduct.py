# #
# dotproduct.py
#
# Leonardo Vencovsky (https://github.com/LeoVen)
#
# 14/08/2018
#
# #
import numpy as np

# Calculating dot product 

def main():
	
	a = np.array([1, 2])
	b = np.array([2, 1])

	# one way of doing it
	dot = 0

	for e, f in zip(a, b):
		dot += e * f

	print("Dot product")
	print(dot)

	print("\nNumpy")
	print(a * b)

	print(np.sum(a * b))

	# or similarly :
	print((a * b).sum())

	# using numpy.dot()
	print(np.dot(a, b))

	# works too
	print(a.dot(b))

	print("\nMagnitude")

	m = np.sqrt( (a * a).sum() )

	print(m)

	# or better (using linalg)
	m = np.linalg.norm(a)

	print(m)

	cosine = a.dot(b) / (np.linalg.norm(a) * np.linalg.norm(b))

	print(cosine)

	angle = np.arccos(cosine)

	print(angle)



if __name__ == '__main__':
	main()