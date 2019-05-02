# Support Vector Regression
# python       = 3.7.3
# numpy        = 1.16.3
# pandas       = 0.24.2
# matplotlib   = 3.0.3
# scikit-learn = 0.20.3
# tensorflow   = 1.13.1

# Importing the libraries
from sklearn.preprocessing import StandardScaler
from sklearn.svm import SVR
import numpy as np
import pandas as pd
import matplotlib.pyplot as plt

# Importing the dataset
dataset = pd.read_csv('Position_Salaries.csv')

# Level
# X.shape == (10,1)
X = dataset.iloc[:, 1:2].values

# Salary
# y.shape == (10,)
y = dataset.iloc[:, 2:3].values

print(X.shape, y.shape)

# SVR requires feature scaling
sc_X = StandardScaler()
X = sc_X.fit_transform(X)
sc_y = StandardScaler()
y = sc_y.fit_transform(y)

print(X.shape, y.shape)

# Fitting SVR to the dataset
regressor = SVR(kernel='rbf', C=1.0, gamma='scale')
regressor.fit(X, y)

# Predict a new result (6.5) expected 160000
# (scalar) Value to be predicted
n = 6.5
# (matrix) Transform value (due to feature scaling)
scale_n = sc_X.transform(np.array([[n]]))
# (matrix) Take prediction (this prediction is scaled)
scale_p = regressor.predict(scale_n)
# (scalar) Inverse scale to get actual result
p = sc_y.inverse_transform(scale_p)[0]

print(f"Prediction for {n} is {p}")

# Visualizing the SVR results
# The last data point (Level 10 with 1000000 salary) is ignored because it is
# considered an outlier
plt.scatter(X, y, c='r')
# Prediction point
plt.scatter(scale_n, scale_p, c='g')
plt.plot(X, regressor.predict(X), c='b')
plt.title("Support Vector Regression")
plt.xlabel("Position Level (scaled)")
plt.ylabel("Salary (scaled)")
plt.show()
