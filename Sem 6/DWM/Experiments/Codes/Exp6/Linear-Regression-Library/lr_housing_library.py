'''
Vedant Sahai 
Batch - C
Roll No 8364
'''

from scipy.io import arff
import pandas as pd
import pylab
import scipy.stats as stats
from sklearn.linear_model import LinearRegression
from sklearn.metrics import mean_squared_error, r2_score
from sklearn.preprocessing import StandardScaler
import matplotlib.pyplot as plt
import seaborn as sns


data = arff.loadarff('house.arff')
df = pd.DataFrame(data[0])
columns = list(df.columns[0:5])
print(df)
train = df[df.columns[0:5]]
test = df[df.columns[5]]
lr = LinearRegression()
lr.fit(train, test)
preds = lr.predict(train)
print("Predicted Values are :\n",preds)
# The coefficients
print('Coefficients: \n', lr.coef_)
# The mean squared error
print('Mean squared error: %.2f'
      % mean_squared_error(test, preds))
# The coefficient of determination: 1 is perfect prediction
print('r squared score: %.2f'
      % r2_score(test, preds))

residuals = test - preds
print("Residual : ",residuals)
plt.plot(train,residuals, 'o', color='darkblue')
plt.title("Residual Plot")
plt.xlabel("Independent Variable")
plt.ylabel("Residual")
plt.show()

'''
     size    land  rooms  granite  extra_bathroom     price
0  1076.0  2801.0    6.0      0.0             0.0  324500.0
1   990.0  3067.0    5.0      1.0             1.0  466000.0
2  1229.0  3094.0    5.0      0.0             1.0  425900.0
3   731.0  4315.0    4.0      1.0             0.0  387120.0
4   671.0  2926.0    4.0      0.0             1.0  312100.0
5  1078.0  6094.0    6.0      1.0             1.0  603000.0
6   909.0  2854.0    5.0      0.0             1.0  383400.0

Predicted Values :
[328483.93639079 468595.17201605 427173.47336172 383136.06360921
 321456.63715632 604388.76437474 368785.95309117]
Coefficients:
 [1.55409757e+02 3.60683253e+01 1.29387132e+04 7.95384753e+04
 7.72825381e+04]
Mean squared error: 49020834.71
r squared score: 0.99
Residual :  0    -3983.936391
1    -2595.172016
2    -1273.473362
3     3983.936391
4    -9356.637156
5    -1388.764375
6    14614.046909
Name: price, dtype: float64
''' 

#Visualization
#quantile-quantile plot
scaler = StandardScaler()
df[columns] = scaler.fit_transform(df[columns].to_numpy())
stats.probplot(df['size'], dist="norm", plot=pylab)
stats.probplot(df['land'], dist="norm", plot=pylab)
stats.probplot(df['rooms'], dist="norm", plot=pylab)
stats.probplot(df['granite'], dist="norm", plot=pylab)
stats.probplot(df['extra_bathroom'], dist="norm", plot=pylab)
pylab.show()
df['Residual']=residuals
stats.probplot(df['Residual'], dist="norm", plot=pylab)
plt.show()
#correlation matrix
plt.matshow(df.corr())
plt.title('Correlation Matrix', fontsize=16)
plt.show()






