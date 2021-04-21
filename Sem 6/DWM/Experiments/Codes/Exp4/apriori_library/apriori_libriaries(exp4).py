'''
Vedant Sahai 
Batch - C
Roll No 8364
'''

import numpy as np 
import pandas as pd 
from mlxtend.frequent_patterns import apriori, association_rules 

# Loading the Data 
data = pd.read_excel('Online Retail.xlsx') 
print(data.head()) 

# Exploring the columns of the data 
print(data.columns) 

# Exploring the different regions of transactions 
print(data.Country.unique()) 

#Step 3: Cleaning the Data

# Stripping extra spaces in the description 
data['Description'] = data['Description'].str.strip() 
  
# Dropping the rows without any invoice number 
data.dropna(axis = 0, subset =['InvoiceNo'], inplace = True) 
data['InvoiceNo'] = data['InvoiceNo'].astype('str') 
  
# Dropping all transactions which were done on credit 
data = data[~data['InvoiceNo'].str.contains('C')] 

#Step 4: Splitting the data according to the region of transaction

# Transactions done in France 
basket_France = (data[data['Country'] =="France"] 
          .groupby(['InvoiceNo', 'Description'])['Quantity'] 
          .sum().unstack().reset_index().fillna(0) 
          .set_index('InvoiceNo')) 
  
# Transactions done in the United Kingdom 
basket_UK = (data[data['Country'] =="United Kingdom"] 
          .groupby(['InvoiceNo', 'Description'])['Quantity'] 
          .sum().unstack().reset_index().fillna(0) 
          .set_index('InvoiceNo')) 
  
# Transactions done in Portugal 
basket_Por = (data[data['Country'] =="Portugal"] 
          .groupby(['InvoiceNo', 'Description'])['Quantity'] 
          .sum().unstack().reset_index().fillna(0) 
          .set_index('InvoiceNo')) 

#Step 5: Hot encoding the Data

# Defining the hot encoding function to make the data suitable  
# for the concerned libraries 
def hot_encode(x): 
    if(x<= 0): 
        return 0
    if(x>= 1): 
        return 1
  
# Encoding the datasets 
basket_encoded = basket_France.applymap(hot_encode) 
basket_France = basket_encoded 
  
basket_encoded = basket_UK.applymap(hot_encode) 
basket_UK = basket_encoded 
  
basket_encoded = basket_Por.applymap(hot_encode) 
basket_Por = basket_encoded 
  

'''
Step 6: Buliding the models and analyzing the results

a) France:

'''
# Building the model 
frq_items = apriori(basket_France, min_support = 0.05, use_colnames = True) 
  
# Collecting the inferred rules in a dataframe 
rules = association_rules(frq_items, metric ="lift", min_threshold = 1) 
rules = rules.sort_values(['confidence', 'lift'], ascending =[False, False]) 
print(rules.head()) 

# #b) United Kingdom:

frq_items = apriori(basket_UK, min_support = 0.05, use_colnames = True) 
rules = association_rules(frq_items, metric ="lift", min_threshold = 1) 
rules = rules.sort_values(['confidence', 'lift'], ascending =[False, False]) 
print(rules.head()) 

# #c) Portugal:

frq_items = apriori(basket_Por, min_support = 0.09, use_colnames = True) 
rules = association_rules(frq_items, metric ="lift", min_threshold = 1) 
rules = rules.sort_values(['confidence', 'lift'], ascending =[False, False]) 
print(rules.head()) 

'''
OUTPUT

InvoiceNo StockCode                          Description  ...  UnitPrice CustomerID         Country
0    536365    85123A   WHITE HANGING HEART T-LIGHT HOLDER  ...       2.55    17850.0  United Kingdom
1    536365     71053                  WHITE METAL LANTERN  ...       3.39    17850.0  United Kingdom
2    536365    84406B       CREAM CUPID HEARTS COAT HANGER  ...       2.75    17850.0  United Kingdom
3    536365    84029G  KNITTED UNION FLAG HOT WATER BOTTLE  ...       3.39    17850.0  United Kingdom
4    536365    84029E       RED WOOLLY HOTTIE WHITE HEART.  ...       3.39    17850.0  United Kingdom

[5 rows x 8 columns]
Index(['InvoiceNo', 'StockCode', 'Description', 'Quantity', 'InvoiceDate',
       'UnitPrice', 'CustomerID', 'Country'],
      dtype='object')
['United Kingdom' 'France' 'Australia' 'Netherlands' 'Germany' 'Norway'
 'EIRE' 'Switzerland' 'Portugal']
                                           antecedents                               consequents  ...  leverage  conviction
100                       (PACK OF 6 SKULL PAPER CUPS)            (PACK OF 6 SKULL PAPER PLATES)  ...  0.047897         inf
267              (PACK OF 6 SKULL PAPER CUPS, POSTAGE)            (PACK OF 6 SKULL PAPER PLATES)  ...  0.047897         inf
269                       (PACK OF 6 SKULL PAPER CUPS)   (PACK OF 6 SKULL PAPER PLATES, POSTAGE)  ...  0.047897         inf
342  (SET/6 RED SPOTTY PAPER PLATES, PACK OF 6 SKUL...    (POSTAGE, SET/6 RED SPOTTY PAPER CUPS)  ...  0.044252         inf
346  (PACK OF 6 SKULL PAPER PLATES, SET/6 RED SPOTT...  (SET/6 RED SPOTTY PAPER PLATES, POSTAGE)  ...  0.044252         inf

[5 rows x 9 columns]
                                            antecedents  ... conviction
3511  (CREAM CUPID HEARTS COAT HANGER, RETRO COFFEE ...  ...        inf
3514  (WOODEN PICTURE FRAME WHITE FINISH, VINTAGE BI...  ...        inf
3567  (CREAM CUPID HEARTS COAT HANGER, RETRO COFFEE ...  ...        inf
3570  (WOODEN PICTURE FRAME WHITE FINISH, VINTAGE BI...  ...        inf
3721  (CREAM CUPID HEARTS COAT HANGER, VINTAGE BILLB...  ...        inf

20   (WOODEN HEART CHRISTMAS SCANDINAVIAN)        (CHRISTMAS RETROSPOT STAR WOOD)  ...  0.113422         inf
21         (CHRISTMAS RETROSPOT STAR WOOD)  (WOODEN HEART CHRISTMAS SCANDINAVIAN)  ...  0.113422         inf
38                (JUMBO BAG PAISLEY PARK)               (LUNCH BAG PAISLEY PARK)  ...  0.113422         inf
39                (LUNCH BAG PAISLEY PARK)               (JUMBO BAG PAISLEY PARK)  ...  0.113422         inf
152     (SET 12 COLOUR PENCILS DOLLY GIRL)       (SET 12 COLOUR PENCILS SPACEBOY)  ...  0.113422         inf

[5 rows x 9 columns]

'''