# Data Preprocessing
# python       = 3.7.3
# numpy        = 1.16.3
# pandas       = 0.24.2
# matplotlib   = 3.0.3
# scikit-learn = 0.20.3
# tensorflow   = 1.13.1

# Importing the libraries
from sklearn.impute import SimpleImputer
from sklearn.preprocessing import LabelEncoder, OneHotEncoder, StandardScaler
from sklearn.model_selection import train_test_split
import numpy as np
import pandas as pd
import matplotlib.pyplot as plt


# Importing the dataset
dataset = pd.read_csv('Data.csv')
# Matrix of features
X = dataset.iloc[:, :-1].values
# independent variable vector
y = dataset.iloc[:, -1].values

# Taking care of missing data
# Create a simple imputer object
imputer = SimpleImputer(missing_values=np.nan, strategy='mean')
# Fit it to the columns we want to fill up the missing values
imputer = imputer.fit(X[:, 1:3])
# Replace missing data
X[:, 1:3] = imputer.transform(X[:, 1:3])

# Encoding categorical data
labelencoder_X = LabelEncoder()
X[:, 0] = labelencoder_X.fit_transform(X[:, 0])
# Adding dummy variables to first column
onehotencoder = OneHotEncoder(categorical_features=[0])
X = onehotencoder.fit_transform(X).toarray()

# Encoding independent variable vector
labelencoder_y = LabelEncoder()
y = labelencoder_y.fit_transform(y)

# Splitting the dataset into the Training set and Test set
X_train, X_test, y_train, y_test = train_test_split(
    X, y, test_size=0.2, random_state=0)

# Feature Scaling
# The StandardScaler defaults to the Standardisation method
sc_X = StandardScaler()
# Feature scaling is also applied to the dummy variables
X_train = sc_X.fit_transform(X_train)
X_test = sc_X.transform(X_test)

# Feature scaling on y depends on what model will be used

print(X_train, end='\n\n')
print(X_test, end='\n\n')
print(y_train, end='\n\n')
print(y_test, end='\n\n')
