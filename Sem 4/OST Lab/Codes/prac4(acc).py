'''
 Title   : Object Oriented Programming and Inheritance
 Name    : Kevlyn Kadamala
 Roll no.: 8340
 '''

accList = []

class Account:

    balance = 500.0
    rate = 0.07
    count = 1000

    def createAccount(self):
        self.name = str(input("Enter your name: "))
        self.address = str(input("Enter address: "))
        self.contact = int(input("Enter contact: "))
        Account.count = Account.count + 1
        self.accno = Account.count

    def computeInterest(self):
        return self.balance*self.rate

    def deposit(self):
        add = int(input("Enter amount of deposit: "))
        self.balance = self.balance + Account.computeInterest(self) + add
        print(f"Account balance is {self.balance}")

    def withdraw(self):
        sub = int(input("Enter amount to withdraw: "))

        if(self.balance - sub < 0):
            print("Cannot withdraw amount")
        else:
            self.balance = self.balance - sub

        print(f"Account balance is {self.balance}")

    def __str__(self):
        return(f"-----Account Details-----\nAccount number: {self.accno}\nAccount name: {self.name}\nBalance: {self.balance}\nAddress: {self.address}\nContact: {self.contact}\n")

def menu(Acc):
    while(True):
        print(f"\n---------Welcome {Acc.name}---------")
        print("Enter 1: Deposit")
        print("Enter 2: Withdraw")
        print("Enter 3: Show details")
        print("Enter 4: Return")
        choice = int(input("Enter: "))

        if(choice == 1):
            Acc.deposit()
        elif(choice == 2):
            Acc.withdraw()
        elif(choice == 3):
            print(Acc)
        elif(choice == 4):
            break
        else:
            print("Wrong choice")

while(True):
    print("\n---------Welcome---------")
    print("Enter 1: Create a new account")
    print("Enter 2: Show all accounts")
    print("Enter 3: Exit")
    ch1 = int(input("Enter: "))

    if(ch1 == 1):
        new = Account()
        new.createAccount()
        menu(new)
        accList.append(new)

    elif(ch1 == 2):
        print("\nList of accounts")

        if(accList):
            for accounts in accList:
                print(accounts.accno)

            accno = int(input("Enter account to be accessed: "))
            acc = None
            for accounts in accList:
                if(accno == accounts.accno):
                    acc = accounts

            if(acc == None):
                print("Account not found")
            else:
                menu(acc)

        else:
            print("No accounts added")

    elif(ch1 == 3):
        print("Exiting, Thank You!")
        break

    else:
        print("Wrong choice")

'''
---------Welcome---------
Enter 1: Create a new account
Enter 2: Show all accounts
Enter 3: Exit
Enter: 1
Enter your name: LOL
Enter address: LMAO
Enter contact: 2314

---------Welcome LOL---------
Enter 1: Deposit
Enter 2: Withdraw
Enter 3: Show details
Enter 4: Return
Enter: 2
Enter amount to withdraw: 480
Account balance is 20.0

---------Welcome LOL---------
Enter 1: Deposit
Enter 2: Withdraw
Enter 3: Show details
Enter 4: Return
Enter: 1
Enter amount of deposit: 20
Account balance is 41.4

---------Welcome LOL---------
Enter 1: Deposit
Enter 2: Withdraw
Enter 3: Show details
Enter 4: Return
Enter: 3
-----Account Details-----
Account number: 1001
Account name: LOL
Balance: 41.4
Address: LMAO
Contact: 2314


---------Welcome LOL---------
Enter 1: Deposit
Enter 2: Withdraw
Enter 3: Show details
Enter 4: Return
Enter: 4

---------Welcome---------
Enter 1: Create a new account
Enter 2: Show all accounts
Enter 3: Exit
Enter: 1
Enter your name: AYYLMAO
Enter address: AYY
Enter contact: 2652134

---------Welcome AYYLMAO---------
Enter 1: Deposit
Enter 2: Withdraw
Enter 3: Show details
Enter 4: Return
Enter: 1
Enter amount of deposit: 1200
Account balance is 1735.0

---------Welcome AYYLMAO---------
Enter 1: Deposit
Enter 2: Withdraw
Enter 3: Show details
Enter 4: Return
Enter: 2
Enter amount to withdraw: 500
Account balance is 1235.0

---------Welcome AYYLMAO---------
Enter 1: Deposit
Enter 2: Withdraw
Enter 3: Show details
Enter 4: Return
Enter: 4

---------Welcome---------
Enter 1: Create a new account
Enter 2: Show all accounts
Enter 3: Exit
Enter: 2

List of accounts
1001
1002
Enter account to be accessed: 1001

---------Welcome LOL---------
Enter 1: Deposit
Enter 2: Withdraw
Enter 3: Show details
Enter 4: Return
Enter: 2
Enter amount to withdraw: 50
Cannot withdraw amount
Account balance is 41.4

---------Welcome LOL---------
Enter 1: Deposit
Enter 2: Withdraw
Enter 3: Show details
Enter 4: Return
Enter: 4

---------Welcome---------
Enter 1: Create a new account
Enter 2: Show all accounts
Enter 3: Exit
Enter: 2

List of accounts
1001
1002
Enter account to be accessed: 213
Account not found

---------Welcome---------
Enter 1: Create a new account
Enter 2: Show all accounts
Enter 3: Exit
Enter: 4
Wrong choice

---------Welcome---------
Enter 1: Create a new account
Enter 2: Show all accounts
Enter 3: Exit
Enter: 3
Exiting, Thank You!
'''
