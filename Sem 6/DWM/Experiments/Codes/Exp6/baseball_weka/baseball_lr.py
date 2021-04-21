from scipy.io import arff
import pandas as pd
import pylab
import scipy.stats as stats
from sklearn.linear_model import LinearRegression
from sklearn.preprocessing import StandardScaler

data = arff.loadarff('baseball.arff')
df = pd.DataFrame(data[0])
columns = list(df.columns[4:])
train = df[df.columns[4:8]]
test = df[df.columns[8]]
lr = LinearRegression()
lr.fit(train, test)
preds = lr.predict(train)

residuals = test - preds
df['Residual'] = residuals

# from sklearn.preprocessing import StandardScaler
# scaler = StandardScaler()
# df[columns] = scaler.fit_transform(df[columns].to_numpy())
# stats.probplot(df['number_of_wins_in_1986'], dist="norm", plot=pylab)
# stats.probplot(df['number_of_losses_in_1986'], dist="norm", plot=pylab)
# stats.probplot(df['attendance_for_home_games_in_1986'], dist="norm", plot=pylab)
# stats.probplot(df['attendance_for_away_games_in_1986'], dist="norm", plot=pylab)
# stats.probplot(df['1987_average_salary'], dist="norm", plot=pylab)
stats.probplot(df['Residual'], dist="norm", plot=pylab)

pylab.show()