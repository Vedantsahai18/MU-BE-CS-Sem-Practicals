'''
Vedant Sahai 
Batch - C
Roll No 8364
'''

from scipy.io import arff
import pandas as pd
import pylab
import scipy.stats as stats
import statsmodels.api as sm

data = arff.loadarff('house.arff')
df = pd.DataFrame(data[0])
columns = list(df.columns[0:5])
print(df)
train = df[df.columns[0:5]]
test = df[df.columns[5]]

train = sm.add_constant(train) # adding a constant

model = sm.OLS(test, train).fit()
predictions = model.predict(train)

print_model = model.summary()
print(print_model)

'''
  OLS Regression Results
==============================================================================
Dep. Variable:                  price   R-squared:                       0.994
Model:                            OLS   Adj. R-squared:                  0.965
Method:                 Least Squares   F-statistic:                     33.96
Date:                Wed, 01 Apr 2020   Prob (F-statistic):              0.130
Time:                        16:14:41   Log-Likelihood:                -71.910
No. Observations:                   7   AIC:                             155.8
Df Residuals:                       1   BIC:                             155.5
Df Model:                           5
Covariance Type:            nonrobust
==================================================================================
                     coef    std err          t      P>|t|      [0.025      0.975]
----------------------------------------------------------------------------------
const           -1.74e+04   4.91e+04     -0.354      0.783   -6.41e+05    6.06e+05
size             155.4098     63.389      2.452      0.247    -650.020     960.839
land              36.0683      9.508      3.794      0.164     -84.740     156.876
rooms           1.294e+04   1.61e+04      0.801      0.570   -1.92e+05    2.18e+05
granite         7.954e+04   2.06e+04      3.866      0.161   -1.82e+05    3.41e+05
extra_bathroom  7.728e+04   1.64e+04      4.718      0.133   -1.31e+05    2.85e+05
==============================================================================
Omnibus:                          nan   Durbin-Watson:                   1.541
Prob(Omnibus):                    nan   Jarque-Bera (JB):                1.062
Skew:                           0.949   Prob(JB):                        0.588
Kurtosis:                       3.200   Cond. No.                     2.77e+04
==============================================================================

Warnings:
[1] Standard Errors assume that the covariance matrix of the errors is correctly specified.
[2] The condition number is large, 2.77e+04. This might indicate that there are
strong multicollinearity or other numerical problems.

'''