# LINEAR REGRESSION
#
# y = b1 * x + b0
#
# To find b0 and b1 there are 2 ways:
#
# 1. Karl's correlation coeff
# 2. Least square method
#
# Steps (using Karl's Correlation Coeff Method):
# 1. Find summation of X (x_sum)
# 2. Find summation of Y (y_sum)
# 3. Find x * y and its summation
# 4. Find (x) ** 2 and its summation
# 5. Find b1 using formula
# 6. Find b0 using formula
# 7. Find y using regression formula

import numpy as np
import pandas as pd
from sklearn.linear_model import LinearRegression

kcoeff = []

df = pd.DataFrame({
    "X" : [0, 1, 2, 3, 4],
    "Y" : [2, 3, 5, 4, 6]
})
def calculateXY():
    df["(X) * (Y)"] = df["X"] * df["Y"]

def calculateXSquare():
    df["(X) ^ 2"] = df["X"] ** 2

def calculateKcoeff(x_val):
    xy_sum = df["(X) * (Y)"].sum()
    x_sum = df["X"].sum()
    y_sum = df["Y"].sum()
    xsquare_sum = df["(X) ^ 2"].sum()
    n = df["X"].count()
    
    X_mean = df["X"].mean()
    Y_mean = df["Y"].mean()
    
    b1 = round((n*xy_sum - (x_sum*y_sum)) / (n*xsquare_sum-pow(x_sum,2)), 2)
    b0 = round(Y_mean - b1 * X_mean, 2)
    kcoeff.append(b0)
    kcoeff.append(b1)
    print(kcoeff)
    print(x_val)
    y = round(kcoeff[0] + kcoeff[1] * x_val, 2)
    return y

def scikitlearn_linear_reg(x_val):
    X = df["X"].values
    X = np.reshape(X, (-1, 1))
    Y = df["Y"].values
    Y = np.reshape(Y, (-1, 1))
    reg = LinearRegression().fit(X, Y)
    y = round(reg.predict(np.array([[x_val]])).flatten()[0], 2)
    return y
    
if __name__ == "__main__":
    x = int(input("Enter x value: "))
    calculateXY()
    calculateXSquare()
    y_custom = calculateKcoeff(x)
    y_scikit = scikitlearn_linear_reg(x)
    print("FINAL DATA:")
    print(df.head(6))
    print(f"For x = {x}")
    print(f"By custom linear regression model: y = {y_custom}")
    print(f"By scikit-learn linear regression model: y = {y_scikit}")

########### OUTPUT ###########

# Enter x value: 10
# [b0, b1] = [2.2, 0.9]
# x = 10
# FINAL DATA:
#    X  Y  (X) * (Y)  (X) ^ 2
# 0  0  2          0        0
# 1  1  3          3        1
# 2  2  5         10        4
# 3  3  4         12        9
# 4  4  6         24       16
# For x = 10
# By custom linear regression model: y = 11.2
# By scikit-learn linear regression model: y = 11.2