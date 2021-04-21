'''
 Title   : Data Structures
 Name    : Kevlyn Kadamala
 Roll no.: 8340
 '''

class Node:
    def __init__(self):
        self.data = 0
        self.next = None

    def push(self, start):
        self.data = int(input("Enter value to be pushed: "))
        self.next = start
        start = self
        return start

    def pop(self, start):

        if(start == None):
            print("List empty")
        else:
            print(f"Popped data: {start.data}")
            start = start.next
        return start

    def disp(self, start):
        ptr = start
        print("Elements in the stack are")
        if(start == None):
            print("List empty")
        else:
            while(ptr != None):
                print(f"{ptr.data}", end = ' ')
                ptr = ptr.next
            print(" ")

a = Node()
b = Node()
c = Node()
d = Node()
e = Node()
f = Node()
start = None
start = a.push(start)
start = b.push(start)
start = c.push(start)
start = d.push(start)
start = e.push(start)
start = f.push(start)
start.disp(start)
start = start.pop(start)
start = start.pop(start)
start = start.pop(start)
start.disp(start)

'''
Enter value to be pushed: 1

Enter value to be pushed: 2

Enter value to be pushed: 3

Enter value to be pushed: 4

Enter value to be pushed: 5

Enter value to be pushed: 6
Elements in the stack are
6 5 4 3 2 1
Popped data: 6
Popped data: 5
Popped data: 4
Elements in the stack are
3 2 1
'''
# --------------------x--------------------
class Node:
    def __init__(self):
        self.data = 0
        self.pri = 10
        self.next = None

    def enque(self, start):
        self.data = int(input("Enter value to be enqueued: "))
        self.pri = int(input("Set priority (Low Value -> High Priority): "))
        ptr = start
        preptr = ptr
        if(start == None):
            start = self
        elif(start.pri > self.pri):
            self.next = start
            start = self
        else:
            while(ptr.next != None and ptr.next.pri <= self.pri):
                preptr = ptr
                ptr = ptr.next

            self.next = ptr.next
            ptr.next = self

        return start

    def deque(self, start):
        if(start == None):
            print("List empty")
        else:
            print(f"Dequeued data: {start.data}")
            start = start.next
        return start

    def disp(self, start):
        ptr = start
        print("Elements in the queue are")
        if(start == None):
            print("List empty")
        else:
            while(ptr != None):
                print(f"{ptr.data}", end = ' ')
                ptr = ptr.next
            print(" ")

a = Node()
b = Node()
c = Node()
d = Node()
e = Node()
f = Node()
start = None
start = a.enque(start)
start = b.enque(start)
start = c.enque(start)
start = d.enque(start)
start = e.enque(start)
start = f.enque(start)
start.disp(start)
start = start.deque(start)
start = start.deque(start)
start = start.deque(start)
start.disp(start)

'''
Enter value to be enqueued: 10
Set priority (Low Value -> High Priority): 2
Enter value to be enqueued: 20
Set priority (Low Value -> High Priority): 0
Enter value to be enqueued: 30
Set priority (Low Value -> High Priority): 1
Enter value to be enqueued: 40
Set priority (Low Value -> High Priority): 3
Enter value to be enqueued: 50
Set priority (Low Value -> High Priority): 4
Enter value to be enqueued: 60
Set priority (Low Value -> High Priority): 0
Elements in the queue are
20 60 30 10 40 50
Dequeued data: 20
Dequeued data: 60
Dequeued data: 30
Elements in the queue are
10 40 50
'''
