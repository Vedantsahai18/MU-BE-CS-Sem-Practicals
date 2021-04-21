"""
'''
Vedant Sahai 
Batch - C
Roll No 8364
'''

"""

from optparse import OptionParser    # parse command-line parameters
from apriori import Apriori

if __name__ == '__main__':      
        
    # Get two important parameters
    filePath = 'transaction.csv'
    print("Enter the minimum support ")
    minSupp  = float(input())
    print("Enter the minimum confidence ")
    minConf  = float(input())
    print("Enter the transaction for which rule has to be calculated ")
    rule=input()
    rhs      = frozenset([rule])
    print("""Parameters: \n - filePath: {} \n - mininum support: {} \n - mininum confidence: {} \n - rhs: {}\n""".\
          format(filePath,minSupp,minConf, rhs))

    # Run and print
    objApriori = Apriori(minSupp, minConf)
    itemCountDict, freqSet = objApriori.fit(filePath)
    for key, value in freqSet.items():
        print('frequent {}-term set:'.format(key))
        print('-'*20)
        for itemset in value:
            print(list(itemset))
        print()

    # Return rules with regard of `rhs`
    rules = objApriori.getSpecRules(rhs)
    print('-'*20)
    print('rules refer to {}'.format(list(rhs)))
    for key, value in rules.items():
        print('{} -> {}: {}'.format(list(key), list(rhs), value))

'''
Transaction:

Bread,Milk 
Bread,Diapers,Beer,Eggs
Milk,Diapers,Beer,Cola
Bread,Milk,Diapers,Beer
Bread,Milk,Diapers,Cola
Bread,Milk
Bread,Cola,Beer,Milk
Milk,Bread,Beer,Cola
Bread,Milk,Diapers,Beer
Bread,Beer,Diapers,Diapers

Ouput:

Enter the minimum support
0.20
Enter the minimum confidence
0.50
Enter the transaction for which rule has to be calculated
Bread
Parameters:
 - filePath: transaction.csv
 - mininum support: 0.2
 - mininum confidence: 0.5
 - rhs: frozenset({'Bread'})

frequent 1-term set:
--------------------
['Milk']
['Bread']
['Beer']
['Cola']
['Diapers']

frequent 2-term set:
--------------------
['Diapers', 'Cola']
['Beer', 'Cola']
['Bread', 'Cola']
['Bread', 'Diapers']
['Beer', 'Diapers']
['Bread', 'Beer']
['Diapers', 'Milk']
['Cola', 'Milk']
['Beer', 'Milk']
['Bread', 'Milk']

frequent 3-term set:
--------------------
['Beer', 'Cola', 'Milk']
['Beer', 'Diapers', 'Milk']
['Bread', 'Beer', 'Milk']
['Diapers', 'Cola', 'Milk']
['Bread', 'Beer', 'Cola']
['Bread', 'Cola', 'Milk']
['Bread', 'Beer', 'Diapers']
['Bread', 'Diapers', 'Milk']

frequent 4-term set:
--------------------
['Diapers', 'Milk', 'Bread', 'Beer']
['Milk', 'Bread', 'Beer', 'Cola']

--------------------
rules refer to ['Bread']
['Cola'] -> ['Bread']: 0.7499999999999999
['Diapers'] -> ['Bread']: 0.8333333333333334
['Beer'] -> ['Bread']: 0.8571428571428572
['Milk'] -> ['Bread']: 0.8749999999999999
['Beer', 'Milk'] -> ['Bread']: 0.8
['Beer', 'Cola'] -> ['Bread']: 0.6666666666666667
['Cola', 'Milk'] -> ['Bread']: 0.7499999999999999
['Beer', 'Diapers'] -> ['Bread']: 0.8
['Diapers', 'Milk'] -> ['Bread']: 0.7499999999999999
['Beer', 'Diapers', 'Milk'] -> ['Bread']: 0.6666666666666667
['Beer', 'Cola', 'Milk'] -> ['Bread']: 0.6666666666666667

'''