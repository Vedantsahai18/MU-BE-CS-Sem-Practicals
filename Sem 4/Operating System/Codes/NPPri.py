from operator import attrgetter

class Process:

	ct = 0
	tat = 0
	wt = 0
	check = False

	def __init__(self, pid, at, bt, priority):
		self.pid = pid
		self.at = at
		self.tempbt = bt
		self.bt = bt
		self.priority = priority

	def atbt(self):
		return f"For Process{self.pid} | Arrival time: {self.at} | Burst time: {self.bt}"

	def __str__(self):
		return f"Process {self.pid} | Arrival time: {self.at} | Burst time: {self.bt} | Priority: {self.priority} | Completion time: {self.ct} | Turn Around Time: {self.tat} | Waiting Time: {self.wt}"

np = int(input("Enter number of processes: "))

prolist = []


for i in range(0, np):
	a = int(input(f"Enter arrival time for Process {i+1}: "))
	b = int(input(f"Enter burst time for Process {i+1}: "))
	p = int(input(f"Enter priority for Process {i+1} (Lower number => Higher priority): "))
	prolist.append(Process(i+1, a, b, p))


prolist = sorted(prolist, key = attrgetter('at', 'priority'))


readyQ = []

print("\n-----------------------------Gantt Chart-----------------------------")

def run():
	i = 0
	j = 0
	sum = 0
	k = 0
	readyQ.append(prolist[i])
	i = i + 1
	while(k < len(readyQ)): # readyQ will keep decreasing as jobs are removed
		k = 0    # Shortest job always at starting of the Queue
		temp = readyQ[k]
		readyQ[k].check = True
		time = 0

		print(f"Time elapsed {sum}")
		print("READY-> ", temp)

		while(time < temp.bt): # Simulation of gantt chart
			for process in prolist:
				if(not process.check and time == process.at):
					process.check = True
					readyQ.append(process)
					readyQ.sort(key = lambda x : x.priority) #Will sort for other jobs that are waiting
					i = i + 1
			time = time + 1

		sum = time + sum
		temp.ct = sum
		j = j + 1
		readyQ.remove(temp)

	return sum

comptime = run()
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
Enter number of processes: 4
Enter arrival time for Process 1: 0
Enter burst time for Process 1: 5
Enter priority for Process 1 (Lower number => Higher priority): 4
Enter arrival time for Process 2: 1
Enter burst time for Process 2: 3
Enter priority for Process 2 (Lower number => Higher priority): 1
Enter arrival time for Process 3: 2
Enter burst time for Process 3: 6
Enter priority for Process 3 (Lower number => Higher priority): 2
Enter arrival time for Process 4: 3
Enter burst time for Process 4: 1
Enter priority for Process 4 (Lower number => Higher priority): 3

-----------------------------Gantt Chart-----------------------------
Time elapsed 0
READY->  Process 1 | Arrival time: 0 | Burst time: 5 | Priority: 4 | Completion time: 0 | Turn Around Time: 0 | Waiting Time: 0
Time elapsed 5
READY->  Process 2 | Arrival time: 1 | Burst time: 3 | Priority: 1 | Completion time: 0 | Turn Around Time: 0 | Waiting Time: 0
Time elapsed 8
READY->  Process 3 | Arrival time: 2 | Burst time: 6 | Priority: 2 | Completion time: 0 | Turn Around Time: 0 | Waiting Time: 0
Time elapsed 14
READY->  Process 4 | Arrival time: 3 | Burst time: 1 | Priority: 3 | Completion time: 0 | Turn Around Time: 0 | Waiting Time: 0
--------------------------------------------------------------

Total completion time is 15

Total turn around time is 36
Average turn around time is 9.0

Total waiting time is 21
Average waiting time is 5.25

Process 1 | Arrival time: 0 | Burst time: 5 | Priority: 4 | Completion time: 5 | Turn Around Time: 5 | Waiting Time: 0
Process 2 | Arrival time: 1 | Burst time: 3 | Priority: 1 | Completion time: 8 | Turn Around Time: 7 | Waiting Time: 4
Process 3 | Arrival time: 2 | Burst time: 6 | Priority: 2 | Completion time: 14 | Turn Around Time: 12 | Waiting Time: 6
Process 4 | Arrival time: 3 | Burst time: 1 | Priority: 3 | Completion time: 15 | Turn Around Time: 12 | Waiting Time: 11
'''
