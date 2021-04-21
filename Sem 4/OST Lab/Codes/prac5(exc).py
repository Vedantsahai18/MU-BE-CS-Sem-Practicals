'''
 Title   : Exception Handling
 Name    : Kevlyn Kadamala
 Roll no.: 8340
 '''

class RangeError(Exception):
   def __str__(self):
       return("\nInvalid range, please enter again\n")

class Subject:

    def __init__(self, name):
        self.name = name

    def checkException(self, upper):
        while(True):

            try:
                marks = int(input(f"Enter marks (out of {upper}): "))
                if(marks > upper or marks < 0):
                    raise RangeError

            except ValueError:
                print("\nSorry there was an error, please enter again\n")
                continue

            except RangeError as e:
                print(e)

            else:
                break
        return marks

    def addMarks(self):

        print(f"Subject: {self.name}")

        print("Theory:")
        self.theory = self.checkException(80)
        print("Internal:")
        self.internal = self.checkException(20)

    def __str__(self):
        return(f"Subject: {self.name}\tInternal: {self.internal}\tTheory: {self.theory}\tTotal (out of 100): {self.theory + self.internal}")

class Student:

    no = 8000

    def addStudent(self):
        self.name = str(input("Enter your name: "))
        self.no = Student.no
        Student.no = Student.no + 1

    def addPython(self):
        self.Python = Subject("Python")
        self.Python.addMarks()

    def addCOA(self):
        self.COA = Subject("COA")
        self.COA.addMarks()

    def addAOA(self):
        self.AOA = Subject("AOA")
        self.AOA.addMarks()

    def enterMarks(self):
        self.addPython()
        self.addCOA()
        self.addAOA()

    def __str__(self):
        return(f"\nName: {self.name}\nRoll no: {self.no}\n{self.Python}\n{self.COA}\n{self.AOA}")

stuList = []

while(True):
    print("\n---------Welcome---------")
    print("Enter 1: Add student")
    print("Enter 2: Show all students")
    print("Enter 3: Exit")

    try:
        ch1 = int(input("Enter: "))
    except ValueError:
        print("\nSorry there was an error, please enter again\n")
        continue

    if(ch1 == 1):
        new = Student()
        new.addStudent()
        new.enterMarks()
        stuList.append(new)

    elif(ch1 == 2):
        print("\nList of students")

        if(stuList):
            for students in stuList:
                print(f"Roll No.: {students.no}\t Name: {students.name}")

            while(True):
                try:
                    rollno = int(input("Enter student roll no. to access: "))
                except ValueError:
                    print("\nSorry there's an error, please enter again\n")
                    continue
                else:
                    break

            stu = None
            for students in stuList:
                if(rollno == students.no):
                    stu = students

            if(stu == None):
                print("Student not found")
            else:
                print(stu)

        else:
            print("No students added")

    elif(ch1 == 3):
        print("Exiting, Thank You!")
        break

    else:
        print("Wrong choice")
'''
---------Welcome---------
Enter 1: Add student
Enter 2: Show all students
Enter 3: Exit
Enter: 1
Enter your name: Kevlyn
Subject: Python
Theory:
Enter marks (out of 80): 45
Internal:
Enter marks (out of 20): 14
Subject: COA
Theory:
Enter marks (out of 80): 364

Invalid range, please enter again

Enter marks (out of 80): 43
Internal:
Enter marks (out of 20): 63

Invalid range, please enter again

Enter marks (out of 20): 12
Subject: AOA
Theory:
Enter marks (out of 80): 3
Internal:
Enter marks (out of 20): 4

---------Welcome---------
Enter 1: Add student
Enter 2: Show all students
Enter 3: Exit
Enter: 2

List of students
Roll No.: 8000	 Name: Kevlyn
Enter student roll no. to access: 8000

Name: Kevlyn
Roll no: 8000
Subject: Python	Internal: 14	Theory: 45	Total (out of 100): 59
Subject: COA	Internal: 12	Theory: 43	Total (out of 100): 55
Subject: AOA	Internal: 4	Theory: 3	Total (out of 100): 7

---------Welcome---------
Enter 1: Add student
Enter 2: Show all students
Enter 3: Exit
Enter: 1
Enter your name: My Name
Subject: Python
Theory:
Enter marks (out of 80): 25
Internal:
Enter marks (out of 20): 47

Invalid range, please enter again

Enter marks (out of 20): 21

Invalid range, please enter again

Enter marks (out of 20): 12
Subject: COA
Theory:
Enter marks (out of 80): 45
Internal:
Enter marks (out of 20): 12
Subject: AOA
Theory:
Enter marks (out of 80): 34
Internal:
Enter marks (out of 20): 12

---------Welcome---------
Enter 1: Add student
Enter 2: Show all students
Enter 3: Exit
Enter: 2

List of students
Roll No.: 8000	 Name: Kevlyn
Roll No.: 8001	 Name: My Name
Enter student roll no. to access: 123
Student not found

---------Welcome---------
Enter 1: Add student
Enter 2: Show all students
Enter 3: Exit
Enter: 2

List of students
Roll No.: 8000	 Name: Kevlyn
Roll No.: 8001	 Name: My Name
Enter student roll no. to access: c

Sorry there's an error, please enter again

Enter student roll no. to access: 8001

Name: My Name
Roll no: 8001
Subject: Python	Internal: 12	Theory: 25	Total (out of 100): 37
Subject: COA	Internal: 12	Theory: 45	Total (out of 100): 57
Subject: AOA	Internal: 12	Theory: 34	Total (out of 100): 46

---------Welcome---------
Enter 1: Add student
Enter 2: Show all students
Enter 3: Exit
Enter: 3
Exiting, Thank You!
'''
