from functools import reduce

import pandas as pd
import pprint

class Classifier():
    data = None
    class_attr = None
    priori = {}
    cp = {}
    hypothesis = None


    def __init__(self,filename=None, class_attr=None ):
        self.data = pd.read_csv(filename, sep=',', header =(0))
        self.class_attr = class_attr

    '''
        probability(class) =    How many  times it appears in cloumn
                             __________________________________________
                                  count of all class attribute
    '''
    def calculate_priori(self):
        class_values = list(set(self.data[self.class_attr]))
        class_data =  list(self.data[self.class_attr])
        for i in class_values:
            self.priori[i]  = class_data.count(i)/float(len(class_data))
        print ("Priori Values: ", self.priori)

    '''
        Here we calculate the individual probabilites 
        P(outcome|evidence) =   P(Likelihood of Evidence) x Prior prob of outcome
                               ____________________________________________________
                                                    P(Evidence)
    '''
    def get_cp(self, attr, attr_type, class_value):
        data_attr = list(self.data[attr])
        print(data_attr)
        class_data = list(self.data[self.class_attr])
        print(class_data)
        total =1
        for i in range(0, len(data_attr)):
            if class_data[i] == class_value and data_attr[i] == attr_type:
                total+=1
        return total/float(class_data.count(class_value))

    '''
        Here we calculate Likelihood of Evidence and multiple all individual probabilities with priori
        (Outcome|Multiple Evidence) = P(Evidence1|Outcome) x P(Evidence2|outcome) x ... x P(EvidenceN|outcome) x P(Outcome)
        scaled by P(Multiple Evidence)
    '''
    def calculate_conditional_probabilities(self, hypothesis):
        for i in self.priori:
            self.cp[i] = {}
            for j in hypothesis:
                self.cp[i].update({ hypothesis[j]: self.get_cp(j, hypothesis[j], i)})
        print ("\n Calculated Conditional Probabilities: \n ")
        pprint.pprint(self.cp)

    def classify(self):
        print ("Result: ")
        for i in self.cp:
            print (i, " ==> ", reduce(lambda x, y: x*y, self.cp[i].values())*self.priori[i])

if __name__ == "__main__":
    c = Classifier(filename="new_dataset.csv", class_attr="Play" )
    c.calculate_priori()
    c.hypothesis = {"Outlook":'Rainy', "Temp":"Mild", "Humidity":'Normal' , "Windy":'t'}

    c.calculate_conditional_probabilities(c.hypothesis)
    c.classify()

'''
OUTPUT

Priori Values:  {'yes': 0.6428571428571429, 'no': 0.35714285714285715}

Calculated Conditional Probabilities:

{'no': {'Mild': 0.6, 'Normal': 0.4, 'Rainy': 0.8, 't': 0.8},
 'yes': {'Mild': 0.5555555555555556,
         'Normal': 0.7777777777777778,
         'Rainy': 0.3333333333333333,
         't': 0.4444444444444444}}
Result:
yes  ==>  0.04115226337448559
no  ==>  0.05485714285714286

'''
