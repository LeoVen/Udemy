# Simple Linear Regression
# python       = 3.7.3
# numpy        = 1.16.3
# pandas       = 0.24.2
# matplotlib   = 3.0.3
# scikit-learn = 0.20.3
# tensorflow   = 1.13.1

# Importing the libraries
import pandas as pd
import matplotlib.pyplot as plt
import numpy as np
from sklearn.linear_model import LinearRegression
from sklearn.model_selection import train_test_split

# Importing the dataset
dataset = pd.read_csv('Salary_Data.csv')
# X.shape == (30, 1)
X = dataset.iloc[:, :-1].values
# y.shape == (30,)
y = dataset.iloc[:, 1].values

# Splitting the dataset into the Training set and Test set
X_train, X_test, y_train, y_test = train_test_split(
    X, y, test_size=1/3, random_state=0)

# No need to apply Feature Scaling

# Fitting Simple Linear Regression to the Training set
regressor = LinearRegression()
regressor.fit(X_train, y_train)

# Predicting the Test set results
y_pred = regressor.predict(X_test)

# Extra

# Take the average deviation
d = np.average([abs(a - b) for a, b in zip(y_pred, y_test)])
# How many results were right between the average deviation
sr = sum(1 if np.isclose(a, b, atol=d) else 0 for a, b in zip(y_pred, y_test))

print(f"{sr} out of {y_test.shape[0]} "
      f"results were relatively close to the actual value")

# End of extra

# Visualising the Training set results
plt.subplot(1, 2, 1)
plt.scatter(X_train, y_train, color='red')
plt.plot(X_train, regressor.predict(X_train), color='blue')
plt.title('Salary vs Experience (Training set)')
plt.xlabel('Years of Experience')
plt.ylabel('Salary')

# Visualising the Test set results
plt.subplot(1, 2, 2)
plt.scatter(X_test, y_test, color='red')
plt.plot(X_test, regressor.predict(X_test), color='blue')
plt.title('Salary vs Experience (Test set)')
plt.xlabel('Years of Experience')
plt.ylabel('Salary')

# Show both plots
plt.tight_layout()
plt.show()
