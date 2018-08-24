# #
# pdf_cdf.py
#
# Leonardo Vencovsky (https://github.com/LeoVen)
#
# 24/08/2018
#
# #
import numpy as np
from scipy.stats import norm

# PDF - Probability density function
# CDF - Cumulative distribution function

def main():
	
	print(norm.pdf(0))

	print(norm.pdf(0, loc=5, scale=10))

	r = np.random.randn(10)

	print(norm.pdf(r))
	print(norm.logpdf(r), end="\n\n")

	print(norm.cdf(r))
	print(norm.logcdf(r), end="\n\n")


if __name__ == '__main__':
	main()