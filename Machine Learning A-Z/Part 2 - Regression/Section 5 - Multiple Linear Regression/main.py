# Multiple Linear Regression
# python       = 3.7.3
# numpy        = 1.16.3
# pandas       = 0.24.2
# matplotlib   = 3.0.3
# scikit-learn = 0.20.3
# tensorflow   = 1.13.1

# Importing the libraries
from sklearn.linear_model import LinearRegression
from sklearn.model_selection import train_test_split
from backward_elimination import backward_elimination
import pandas as pd
import matplotlib.pyplot as plt
import numpy as np
import scipy as sp
import statsmodels.formula.api as sm

# Importing the dataset
dataset = pd.read_csv('50_Startups.csv')

# Encoding categorical data and avoiding the Dummy Variable Trap
# drop_first means we drop one of the dummy variables
# dataset.shape == (50, 6)
dataset = pd.get_dummies(dataset, columns=["State"], drop_first=True)
print(dataset.shape)

# Separating dependent variable from independent variables
# X.shape == (50, 5)
X = dataset.iloc[:, [0, 1, 2, 4, 5]].values
print(X.shape)
# y.shape == (50,)
y = dataset.iloc[:, 3].values
print(y.shape)

X_train, X_test, y_train, y_test = train_test_split(
    X, y, test_size=0.2, random_state=0)

# Fitting Multiple Linear Regression to the Training set
regressor = LinearRegression()
regressor.fit(X_train, y_train)

# Predicting the Test set results
y_pred = regressor.predict(X_test)

# Extra

# Checking how the regressor function looks like
x_space = np.linspace(-100, 100, 200)
y_space = sp.polyval(regressor.coef_, x_space)

# plt.plot(x_space, y_space)
# plt.show()

# End of Extra

# Backward Elimination
# Building the optimal model
# Appending X to b0 (where b0 is 'a' in the polynomial 'y = a + bx + cx^2 ...')
# arr - target
# axis - 0 for row, 1 for column (to append)
X = np.append(arr=np.ones((50, 1)).astype(int), values=X, axis=1)

# Optimal matrix of features (independent variables) that are statistically significant
# (Only variables with high impact in y 'Profit')

# In the process of backward elimination...
# Remove highest (x5 == 0.990)
# Remove highest (x4 == 0.940)
# Remove highest (x2 == 0.602)
# Done
X_opt = X[:, [0, 1, 3]]
# X_opt = X[:, [0, 1, 2, 3, 4, 5]]

# Ordinary Least Squares
regressor_ols = sm.OLS(endog=y, exog=X_opt).fit()

# Getting summary
print(regressor_ols.summary())

# Columns where P value is greater than 0.05 (found from summary)
# x2, x3, x4, x5

# Using Automatic backward elimination found in file backward_elimination.py
backward_elimination(X, y, 0.05)
