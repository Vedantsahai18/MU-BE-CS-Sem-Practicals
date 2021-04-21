# -*- coding: utf-8 -*-
"""MNIST-scratch.ipynb
'''
//Mayank Mishra
//Batch B
Roll No 8348

'''

"""

# Commented out IPython magic to ensure Python compatibility.
import numpy as np
from sklearn.metrics import classification_report, confusion_matrix
import matplotlib.pyplot as plt
# %matplotlib inline

from sklearn.datasets import fetch_openml
mnist = fetch_openml('mnist_784')

X, y = mnist["data"], mnist["target"]
digits = 10
examples = y.shape[0]

y = y.reshape(1, examples)

Y_new = np.eye(digits)[y.astype('int32')]
Y_new = Y_new.T.reshape(digits, examples)

m = 60000
m_test = X.shape[0] - m

X_train, X_test = X[:m].T, X[m:].T
Y_train, Y_test = Y_new[:,:m], Y_new[:,m:]

shuffle_index = np.random.permutation(m)
X_train, Y_train = X_train[:, shuffle_index], Y_train[:, shuffle_index]

import matplotlib
i = 12
plt.imshow(X_train[:,i].reshape(28,28), cmap = matplotlib.cm.binary)
plt.axis("off")
plt.show()
Y_train[:,i]

def sigmoid(z):
    s = 1 / (1 + np.exp(-z))
    return s

def compute_multiclass_loss(Y, Y_hat):

    L_sum = np.sum(np.multiply(Y, np.log(Y_hat)))
    m = Y.shape[1]
    L = -(1/m) * L_sum

    return L

n_x = X_train.shape[0]
n_h = 64
learning_rate = 1

W1 = np.random.randn(n_h, n_x)
b1 = np.zeros((n_h, 1))
W2 = np.random.randn(digits, n_h)
b2 = np.zeros((digits, 1))

X = X_train
Y = Y_train

for i in range(200):

    Z1 = np.matmul(W1,X) + b1
    A1 = sigmoid(Z1)
    Z2 = np.matmul(W2,A1) + b2
    A2 = np.exp(Z2) / np.sum(np.exp(Z2), axis=0)

    cost = compute_multiclass_loss(Y, A2)

    dZ2 = A2-Y
    dW2 = (1./m) * np.matmul(dZ2, A1.T)
    db2 = (1./m) * np.sum(dZ2, axis=1, keepdims=True)

    dA1 = np.matmul(W2.T, dZ2)
    dZ1 = dA1 * sigmoid(Z1) * (1 - sigmoid(Z1))
    dW1 = (1./m) * np.matmul(dZ1, X.T)
    db1 = (1./m) * np.sum(dZ1, axis=1, keepdims=True)

    W2 = W2 - learning_rate * dW2
    b2 = b2 - learning_rate * db2
    W1 = W1 - learning_rate * dW1
    b1 = b1 - learning_rate * db1

    print("Epoch", i, "cost: ", cost)

print("Final cost:", cost)

Z1 = np.matmul(W1, X_test) + b1
A1 = sigmoid(Z1)
Z2 = np.matmul(W2, A1) + b2
A2 = np.exp(Z2) / np.sum(np.exp(Z2), axis=0)

predictions = np.argmax(A2, axis=0)
labels = np.argmax(Y_test, axis=0)

print(confusion_matrix(predictions, labels))
print(classification_report(predictions, labels))

'''
  s = 1 / (1 + np.exp(-z))
Epoch 0 cost:  8.38257425626798
Epoch 1 cost:  6.381191845037284
Epoch 2 cost:  5.279595345143765
Epoch 3 cost:  4.697088228810115
Epoch 4 cost:  4.28116614557831
Epoch 5 cost:  3.938590961391657
Epoch 6 cost:  3.636218064031119
Epoch 7 cost:  3.399307728676299
Epoch 8 cost:  3.177310701902954
Epoch 9 cost:  2.9958341061652076
Epoch 10 cost:  2.842289112830531
Epoch 11 cost:  2.7001518489751937
Epoch 12 cost:  2.576689125356032
Epoch 13 cost:  2.464457962971856
Epoch 14 cost:  2.35050686012061
Epoch 15 cost:  2.2584430996501728
Epoch 16 cost:  2.1780671296908785
Epoch 17 cost:  2.1013738318684307
Epoch 18 cost:  2.0369170519761455
Epoch 19 cost:  1.9782777574585504
Epoch 20 cost:  1.91905361219936
Epoch 21 cost:  1.8691733152321601
Epoch 22 cost:  1.8173529887599418
Epoch 23 cost:  1.7707572254966135
Epoch 24 cost:  1.7244734939007538
Epoch 25 cost:  1.679960662846841
Epoch 26 cost:  1.643782479605174
Epoch 27 cost:  1.6081616239810788
Epoch 28 cost:  1.5775509962621281
Epoch 29 cost:  1.5430712251005165
Epoch 30 cost:  1.5113744300150416
Epoch 31 cost:  1.4825191457897728
Epoch 32 cost:  1.4553781422904852
Epoch 33 cost:  1.4290501608820072
Epoch 34 cost:  1.4054032259224452
Epoch 35 cost:  1.3822131032765472
Epoch 36 cost:  1.3629361480273219
Epoch 37 cost:  1.3424448505565298
Epoch 38 cost:  1.321414727919012
Epoch 39 cost:  1.3057814240237122
Epoch 40 cost:  1.2874239054945948
Epoch 41 cost:  1.2695143980749217
Epoch 42 cost:  1.2512473576545713
Epoch 43 cost:  1.2351597011082986
Epoch 44 cost:  1.2204526506972584
Epoch 45 cost:  1.2059221760206358
Epoch 46 cost:  1.195118906666485
Epoch 47 cost:  1.1807096040338985
Epoch 48 cost:  1.1696748446255163
Epoch 49 cost:  1.1610445188387997
Epoch 50 cost:  1.146954204539167
Epoch 51 cost:  1.135822085888144
Epoch 52 cost:  1.1233986058756542
Epoch 53 cost:  1.112485507187176
Epoch 54 cost:  1.1035317374342524
Epoch 55 cost:  1.0936511011338041
Epoch 56 cost:  1.084576266333851
Epoch 57 cost:  1.0748070746271976
Epoch 58 cost:  1.0658761564700385
Epoch 59 cost:  1.0559619157694777
Epoch 60 cost:  1.0485144544214524
Epoch 61 cost:  1.03916063019943
Epoch 62 cost:  1.0322585025220836
Epoch 63 cost:  1.024254398824036
Epoch 64 cost:  1.01455504262039
Epoch 65 cost:  1.0080276446856349
Epoch 66 cost:  1.0028337622645496
Epoch 67 cost:  0.9929439074493916
Epoch 68 cost:  0.9857802841028319
Epoch 69 cost:  0.9784184889609122
Epoch 70 cost:  0.9722625099589852
Epoch 71 cost:  0.965125680405402
Epoch 72 cost:  0.9597772007489692
Epoch 73 cost:  0.9530506189298689
Epoch 74 cost:  0.9493911332512046
Epoch 75 cost:  0.9420172248096488
Epoch 76 cost:  0.9348639347492911
Epoch 77 cost:  0.9300863114383916
Epoch 78 cost:  0.9267937444932441
Epoch 79 cost:  0.9204384281582788
Epoch 80 cost:  0.9179297162330752
Epoch 81 cost:  0.9097743584173913
Epoch 82 cost:  0.9044853177869352
Epoch 83 cost:  0.9014474550233563
Epoch 84 cost:  0.8963569682649332
Epoch 85 cost:  0.8921378443411895
Epoch 86 cost:  0.885909186631787
Epoch 87 cost:  0.8821833316241485
Epoch 88 cost:  0.878176799869047
Epoch 89 cost:  0.8736462662488239
Epoch 90 cost:  0.8702511406466541
Epoch 91 cost:  0.8654911229726145
Epoch 92 cost:  0.8629922168766225
Epoch 93 cost:  0.8574111884514617
Epoch 94 cost:  0.8529274840242023
Epoch 95 cost:  0.8493148821266316
Epoch 96 cost:  0.8459727619207013
Epoch 97 cost:  0.8427246902669243
Epoch 98 cost:  0.8387783606145858
Epoch 99 cost:  0.8335540635038327
Epoch 100 cost:  0.8307123909108766
Epoch 101 cost:  0.8276527627891652
Epoch 102 cost:  0.824460398916827
Epoch 103 cost:  0.8210025945035476
Epoch 104 cost:  0.8183161717344251
Epoch 105 cost:  0.8129715556157857
Epoch 106 cost:  0.8118644671211802
Epoch 107 cost:  0.8091006640480223
Epoch 108 cost:  0.805800719574829
Epoch 109 cost:  0.8020515641725342
Epoch 110 cost:  0.8002647782550039
Epoch 111 cost:  0.7955473743381914
Epoch 112 cost:  0.7934450798868905
Epoch 113 cost:  0.7909182203565207
Epoch 114 cost:  0.7874203266126348
Epoch 115 cost:  0.7845438189600831
Epoch 116 cost:  0.78256300678829
Epoch 117 cost:  0.7809567706164242
Epoch 118 cost:  0.7776799493646893
Epoch 119 cost:  0.7739117044991156
Epoch 120 cost:  0.7718246195392493
Epoch 121 cost:  0.7691369354614158
Epoch 122 cost:  0.7659369449794012
Epoch 123 cost:  0.7628903399472206
Epoch 124 cost:  0.7616457559106792
Epoch 125 cost:  0.7604566144681153
Epoch 126 cost:  0.7582604452775894
Epoch 127 cost:  0.7551863912181016
Epoch 128 cost:  0.7522526542866199
Epoch 129 cost:  0.7501216141083674
Epoch 130 cost:  0.7466845437751176
Epoch 131 cost:  0.7453380929068891
Epoch 132 cost:  0.7432387624702562
Epoch 133 cost:  0.742008540326208
Epoch 134 cost:  0.7386655943233817
Epoch 135 cost:  0.7378078948655941
Epoch 136 cost:  0.7354373171632954
Epoch 137 cost:  0.7342781453150815
Epoch 138 cost:  0.7321810661605529
Epoch 139 cost:  0.7297244880172268
Epoch 140 cost:  0.7291351570660637
Epoch 141 cost:  0.7273564091307911
Epoch 142 cost:  0.7254005457129679
Epoch 143 cost:  0.7227580327026331
Epoch 144 cost:  0.7219039638885896
Epoch 145 cost:  0.718160456000921
Epoch 146 cost:  0.7172141017472601
Epoch 147 cost:  0.7157019083644803
Epoch 148 cost:  0.7148392348197103
Epoch 149 cost:  0.7142557478829548
Epoch 150 cost:  0.7110751865227188
Epoch 151 cost:  0.7093497883316039
Epoch 152 cost:  0.7082384715436584
Epoch 153 cost:  0.7065562814608897
Epoch 154 cost:  0.7032674423091843
Epoch 155 cost:  0.7024545089409995
Epoch 156 cost:  0.7016962649358538
Epoch 157 cost:  0.6993581497151026
Epoch 158 cost:  0.6997262032230466
Epoch 159 cost:  0.6966342520367289
Epoch 160 cost:  0.6954907746056697
Epoch 161 cost:  0.6936980847550775
Epoch 162 cost:  0.6933009908057373
Epoch 163 cost:  0.6911504239770008
Epoch 164 cost:  0.6882188171958348
Epoch 165 cost:  0.6867690201241244
Epoch 166 cost:  0.6861213007958759
Epoch 167 cost:  0.6848064989095263
Epoch 168 cost:  0.684683456114083
Epoch 169 cost:  0.6819867905543104
Epoch 170 cost:  0.6804278125687119
Epoch 171 cost:  0.6820541255858898
Epoch 172 cost:  0.6779083166607524
Epoch 173 cost:  0.6774683808847046
Epoch 174 cost:  0.6749008785045144
Epoch 175 cost:  0.67443895354431
Epoch 176 cost:  0.6724047614073826
Epoch 177 cost:  0.6716487241548467
Epoch 178 cost:  0.6718339780189758
Epoch 179 cost:  0.6697400022821278
Epoch 180 cost:  0.668655979088335
Epoch 181 cost:  0.6661570493352964
Epoch 182 cost:  0.6659598825924312
Epoch 183 cost:  0.6637542113492776
Epoch 184 cost:  0.6639856991504095
Epoch 185 cost:  0.6624545547661643
Epoch 186 cost:  0.6614385544166448
Epoch 187 cost:  0.6596927553055962
Epoch 188 cost:  0.6585422883129002
Epoch 189 cost:  0.6568607570758888
Epoch 190 cost:  0.6550891825463423
Epoch 191 cost:  0.6547109693984365
Epoch 192 cost:  0.6544281807322522
Epoch 193 cost:  0.6527545627677539
Epoch 194 cost:  0.6521834597263717
Epoch 195 cost:  0.6507221871719828
Epoch 196 cost:  0.6500611714510647
Epoch 197 cost:  0.6487309941658975
Epoch 198 cost:  0.6463511426128139
Epoch 199 cost:  0.6458755216847104
Final cost: 0.6458755216847104
[[ 848    0   20    5    7   46   48    8    8   10]
 [   1 1073   36    7    6    6    6   20   14    8]
 [  15   16  788   34   12   23   41   31   45   21]
 [  15   10   34  788    9   73    2   13   59   10]
 [   6    2   25    6  787   21   20   25   18  105]
 [  44    2   11   65   10  592   29    5   60   20]
 [  32    3   43    7   25   27  792    2   28    9]
 [   5    4   25   20   11   14    1  831   19   66]
 [   8   23   44   60   20   69   16   16  682   28]
 [   6    2    6   18   95   21    3   77   41  732]]
              precision    recall  f1-score   support

           0       0.87      0.85      0.86      1000
           1       0.95      0.91      0.93      1177
           2       0.76      0.77      0.77      1026
           3       0.78      0.78      0.78      1013
           4       0.80      0.78      0.79      1015
           5       0.66      0.71      0.68       838
           6       0.83      0.82      0.82       968
           7       0.81      0.83      0.82       996
           8       0.70      0.71      0.70       966
           9       0.73      0.73      0.73      1001

    accuracy                           0.79     10000
   macro avg       0.79      0.79      0.79     10000
weighted avg       0.79      0.79      0.79     10000

'''