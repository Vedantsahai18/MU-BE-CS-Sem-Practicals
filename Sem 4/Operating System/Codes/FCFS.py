class Process:

	ct = 0
	tat = 0
	wt = 0

	def __init__(self, pid, at, bt):
		self.pid = pid
		self.at = at
		self.bt = bt

	def atbt(self):
		return f"For Process{self.pid} | Arrival time: {self.at} | Burst time: {self.bt}"

	def __str__(self):
		return f"Process {self.pid} | Arrival time: {self.at} | Burst time: {self.bt} | Completion time: {self.ct} | Turn Around Time: {self.tat} | Waiting Time: {self.wt}"

np = int(input("Enter number of processes: "))

prolist = []


for i in range(0, np):
	a = int(input(f"Enter arrival time for Process {i+1}: "))
	b = int(input(f"Enter burst time for Process {i+1}: "))
	prolist.append(Process(i+1, a, b))


prolist.sort(key = lambda x: x.at)

print("\n-----------------------------Gantt Chart-----------------------------")

def gantt():
	sum = 0
	for process in range(0, np):
		print(f"Time elapsed {sum}")
		print("READY-> ", prolist[process])
		sum = sum + prolist[process].bt
		prolist[process].ct = sum
	return sum

comptime = gantt()
print("--------------------------------------------------------------")

print(f"\nTotal completion time is {comptime}")



def ttat():
	ttat = 0
	for process in range(0, np):
		prolist[process].tat = prolist[process].ct - prolist[process].at
		ttat = ttat + prolist[process].tat
	return ttat
ttat = ttat()
print(f"\nTotal turn around time is {ttat}")
print(f"Average turn around time is {ttat/np}")

def twt():
	twt = 0
	for process in range(0, np):
		prolist[process].wt = prolist[process].tat - prolist[process].bt
		twt = twt + prolist[process].wt
	return twt

twt = twt()
print(f"\nTotal waiting time is {twt}")
print(f"Average waiting time is {twt/np}\n")


for process in range(0, np):
	print(prolist[process])

'''
Enter number of processes: 5
Enter arrival time for Process 1: 0
Enter burst time for Process 1: 2
Enter arrival time for Process 2: 1
Enter burst time for Process 2: 6
Enter arrival time for Process 3: 2
Enter burst time for Process 3: 4
Enter arrival time for Process 4: 3
Enter burst time for Process 4: 9
Enter arrival time for Process 5: 4
Enter burst time for Process 5: 12

-----------------------------Gantt Chart-----------------------------
Time elapsed 0
READY->  Process 1 | Arrival time: 0 | Burst time: 2 | Completion time: 0 | Turn Around Time: 0 | Waiting Time: 0
Time elapsed 2
READY->  Process 2 | Arrival time: 1 | Burst time: 6 | Completion time: 0 | Turn Around Time: 0 | Waiting Time: 0
Time elapsed 8
READY->  Process 3 | Arrival time: 2 | Burst time: 4 | Completion time: 0 | Turn Around Time: 0 | Waiting Time: 0
Time elapsed 12
READY->  Process 4 | Arrival time: 3 | Burst time: 9 | Completion time: 0 | Turn Around Time: 0 | Waiting Time: 0
Time elapsed 21
READY->  Process 5 | Arrival time: 4 | Burst time: 12 | Completion time: 0 | Turn Around Time: 0 | Waiting Time: 0
--------------------------------------------------------------

Total completion time is 33

Total turn around time is 66
Average turn around time is 13.2

Total waiting time is 33
Average waiting time is 6.6

Process 1 | Arrival time: 0 | Burst time: 2 | Completion time: 2 | Turn Around Time: 2 | Waiting Time: 0
Process 2 | Arrival time: 1 | Burst time: 6 | Completion time: 8 | Turn Around Time: 7 | Waiting Time: 1
Process 3 | Arrival time: 2 | Burst time: 4 | Completion time: 12 | Turn Around Time: 10 | Waiting Time: 6
Process 4 | Arrival time: 3 | Burst time: 9 | Completion time: 21 | Turn Around Time: 18 | Waiting Time: 9
Process 5 | Arrival time: 4 | Burst time: 12 | Completion time: 33 | Turn Around Time: 29 | Waiting Time: 17

-----------------------------XXXX-----------------------------

Enter number of processes: 5
Enter arrival time for Process 1: 0
Enter burst time for Process 1: 2
Enter arrival time for Process 2: 1
Enter burst time for Process 2: 3
Enter arrival time for Process 3: 2
Enter burst time for Process 3: 5
Enter arrival time for Process 4: 3
Enter burst time for Process 4: 4
Enter arrival time for Process 5: 4
Enter burst time for Process 5: 6

-----------------------------Gantt Chart-----------------------------
Time elapsed 0
READY->  Process 1 | Arrival time: 0 | Burst time: 2 | Completion time: 0 | Turn Around Time: 0 | Waiting Time: 0
Time elapsed 2
READY->  Process 2 | Arrival time: 1 | Burst time: 3 | Completion time: 0 | Turn Around Time: 0 | Waiting Time: 0
Time elapsed 5
READY->  Process 3 | Arrival time: 2 | Burst time: 5 | Completion time: 0 | Turn Around Time: 0 | Waiting Time: 0
Time elapsed 10
READY->  Process 4 | Arrival time: 3 | Burst time: 4 | Completion time: 0 | Turn Around Time: 0 | Waiting Time: 0
Time elapsed 14
READY->  Process 5 | Arrival time: 4 | Burst time: 6 | Completion time: 0 | Turn Around Time: 0 | Waiting Time: 0
--------------------------------------------------------------

Total completion time is 20

Total turn around time is 41
Average turn around time is 8.2

Total waiting time is 21
Average waiting time is 4.2

Process 1 | Arrival time: 0 | Burst time: 2 | Completion time: 2 | Turn Around Time: 2 | Waiting Time: 0
Process 2 | Arrival time: 1 | Burst time: 3 | Completion time: 5 | Turn Around Time: 4 | Waiting Time: 1
Process 3 | Arrival time: 2 | Burst time: 5 | Completion time: 10 | Turn Around Time: 8 | Waiting Time: 3
Process 4 | Arrival time: 3 | Burst time: 4 | Completion time: 14 | Turn Around Time: 11 | Waiting Time: 7
Process 5 | Arrival time: 4 | Burst time: 6 | Completion time: 20 | Turn Around Time: 16 | Waiting Time: 10
'''
