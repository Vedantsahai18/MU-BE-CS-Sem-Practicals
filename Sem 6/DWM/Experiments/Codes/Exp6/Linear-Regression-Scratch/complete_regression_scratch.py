'''
Vedant Sahai 
Batch - C
Roll No 8364
'''

import numpy as np 
import matplotlib.pyplot as plt 
import math 
  
def rmse(x,y):
     # number of observations/points 
    n = np.size(x) 
  
    # mean of x and y vector 
    m_x, m_y = np.mean(x), np.mean(y) 

    # SS_{xx} = \sum_{i=1}^{n} (x_i-\bar{x})^2 =  \sum_{i=1}^{n}x_i^2 - n(\bar{x})^2 
    SS_xx = np.sum(x*x) - n*m_x*m_x

    SS_yy = np.sum(y*y) - n*m_y*m_y

    # SS_{xy} = \sum_{i=1}^{n} (x_i-\bar{x})(y_i-\bar{y}) =  \sum_{i=1}^{n} y_ix_i - n\bar{x}\bar{y} 
    SS_xy = np.sum(y*x) - n*m_y*m_x

    stdx=math.sqrt(SS_xx/n)
    stdy=math.sqrt(SS_yy/n)

    rmse=(1/n)*(SS_xy)/(stdx*stdy)
    
    print("The RMSE of the linear regression model is :",rmse)
    
    if(0.2<rmse<0.4):
        print("Very weakly correlated")
    elif (0.4<rmse<0.6):
        print(" Weakly correlated ")
    elif( 0.6<rmse<0.8):  
        print(" Strongly Correlated")
    else:
        print("Very Strongly Correlated")
        
    
def estimate_coef(x, y): 
    # number of observations/points 
    n = np.size(x) 
  
    # mean of x and y vector 
    m_x, m_y = np.mean(x), np.mean(y) 
  
    # calculating cross-deviation and deviation about x 
    # SS_{xy} = \sum_{i=1}^{n} (x_i-\bar{x})(y_i-\bar{y}) =  \sum_{i=1}^{n} y_ix_i - n\bar{x}\bar{y} 
    SS_xy = np.sum(y*x) - n*m_y*m_x 

    # SS_{xx} = \sum_{i=1}^{n} (x_i-\bar{x})^2 =  \sum_{i=1}^{n}x_i^2 - n(\bar{x})^2 
    SS_xx = np.sum(x*x) - n*m_x*m_x 
  
    # calculating regression coefficients 
    b_1 = SS_xy / SS_xx 
    b_0 = m_y - b_1*m_x 
  
    return(b_0, b_1) 
  
def plot_regression_line(x, y, b): 
    # plotting the actual points as scatter plot 
    plt.scatter(x, y, color = "m", 
               marker = "o", s = 30) 
  
    # predicted response vector 
    y_pred = b[0] + b[1]*x 
  
    # plotting the regression line 
    plt.plot(x, y_pred, color = "g") 
  
    # putting labels 
    plt.xlabel('x') 
    plt.ylabel('y') 
  
    # function to show plot 
    plt.show() 
  
def main(): 
    # observations 
    x = np.array([20,60,100,140,180,220,260,300,340,380]) 
    y = np.array([0.18, 0.37, 0.35, 0.78, 0.56, 0.75, 1.18, 1.36, 1.17, 1.65]) 
  
    # estimating coefficients 
    b = estimate_coef(x, y) 
    print("Estimated coefficients:b_0 = {} b_1 = {}".format(b[0], b[1])) 
    
    print("The equation is y = ",b[0],"+",b[1]," * x ")

    print("Enter the x value to get predicted value")
    x1=float(input())
    y_pred1 = b[0] + b[1]*x1
    print("The predicted value is :", y_pred1)

    rmse(x,y)
  
    # plotting regression line 
    plot_regression_line(x, y, b) 


if __name__ == "__main__": 
    main() 

#OUTPUT
#Estimated coefficients:b_0 = 0.0692424242424241 b_1 = 0.0038287878787878794
#The equation is y =  0.0692424242424 + 0.00382878787879  * x 
#Enter the x value to get predicted value
#240
#The predicted value is : 0.9881515151515152
#The RMSE of the linear regression model is : 0.9514813712820606
#Very Strongly Correlated
