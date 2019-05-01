# Polynomial Linear Regression
# python       = 3.7.3
# numpy        = 1.16.3
# pandas       = 0.24.2
# matplotlib   = 3.0.3
# scikit-learn = 0.20.3
# tensorflow   = 1.13.1

# Importing the libraries
from sklearn.preprocessing import PolynomialFeatures
from sklearn.linear_model import LinearRegression
import numpy as np
import scipy as sp
import pandas as pd
import matplotlib.pyplot as plt

# Importing the dataset
dataset = pd.read_csv('Position_Salaries.csv')

# Level
# X.shape == (10,)
X = dataset.iloc[:, 1].values

# Salary
# y.shape == (10,)
y = dataset.iloc[:, 2].values

print(f"X shape = {X.shape}\ny shape = {y.shape}")

# Using scipy's polyfit and polyval
coef1 = sp.polyfit(X, y, 1)
coef2 = sp.polyfit(X, y, 2)
coef3 = sp.polyfit(X, y, 3)
coef4 = sp.polyfit(X, y, 4)

print(f"Coef1 = {coef1}")
print(f"Coef2 = {coef2}")
print(f"Coef3 = {coef3}")
print(f"Coef4 = {coef4}")

# Data points to make curves smoother
x_space = np.linspace(1, 10, 100)

# Predicting
print(f"Prediction by degree 1 {sp.polyval(coef1, 6.5)}")
print(f"Prediction by degree 2 {sp.polyval(coef2, 6.5)}")
print(f"Prediction by degree 3 {sp.polyval(coef3, 6.5)}")
print(f"Prediction by degree 4 {sp.polyval(coef4, 6.5)}")

# Plotting polynomial regressions of (1, 2, 3, 4)

# 1
plt.subplot(2, 2, 1)
plt.title("Linear Regression degree 1")
# Prediction
plt.scatter(6.5, 160000, c='g')
plt.scatter(X, y, c='r')
plt.plot(x_space, sp.polyval(coef1, x_space))

# 2
plt.subplot(2, 2, 2)
plt.title("Linear Regression degree 2")
# Prediction
plt.scatter(6.5, 160000, c='g')
plt.scatter(X, y, c='r')
plt.plot(x_space, sp.polyval(coef2, x_space))

# 3
plt.subplot(2, 2, 3)
plt.title("Linear Regression degree 3")
# Prediction
plt.scatter(6.5, 160000, c='g')
plt.scatter(X, y, c='r')
plt.plot(x_space, sp.polyval(coef3, x_space))

# 4
plt.subplot(2, 2, 4)
plt.title("Linear Regression degree 4")
# Prediction
plt.scatter(6.5, 160000, c='g')
plt.scatter(X, y, c='r')
plt.plot(x_space, sp.polyval(coef4, x_space))

# Show graphs
plt.tight_layout()
plt.show()
