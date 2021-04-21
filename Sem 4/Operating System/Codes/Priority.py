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

def gantt():
	sum = 0
	for process in range(0, np):
		sum = sum + prolist[process].bt
		prolist[process].ct = sum
	return sum



readyQ = []

print("\n-----------------------------Gantt Chart-----------------------------")

def run():
	i = 0
	count = 0
	k = 0
	readyQ.append(prolist[i])
	i = i + 1
	while(k < len(readyQ)): # readyQ will keep decreasing as jobs are removed
		k = 0    # High Priority job always at starting of the Queue
		brk = False
		temp = readyQ[k]
		temp.check = True


		print(f"Time elapsed {count}")
		print("READY-> ", temp)

		while(temp.tempbt > 0): # Simulation of gantt chart

			for process in prolist:

				if(not process.check and count >= process.at):
					process.check = True
					readyQ.append(process)
					readyQ.sort(key = lambda x : x.priority)

					if(temp.priority > process.priority):
						brk = True
						break
					else:
						pass

			if(brk):
				break # To break from outer while loop (Premptive)
			else:
				pass


			count = count + 1 # Because of premption, count increments by 1
			temp.tempbt = temp.tempbt - 1

		temp.ct = count
		if(temp.tempbt == 0):
			readyQ.remove(temp)

	return count

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
Enter number of processes: 5
Enter arrival time for Process 1: 0
Enter burst time for Process 1: 10
Enter priority for Process 1 (Lower number => Higher priority): 3
Enter arrival time for Process 2: 0
Enter burst time for Process 2: 1
Enter priority for Process 2 (Lower number => Higher priority): 1
Enter arrival time for Process 3: 0
Enter burst time for Process 3: 2
Enter priority for Process 3 (Lower number => Higher priority): 4
Enter arrival time for Process 4: 0
Enter burst time for Process 4: 1
Enter priority for Process 4 (Lower number => Higher priority): 5
Enter arrival time for Process 5: 0
Enter burst time for Process 5: 5
Enter priority for Process 5 (Lower number => Higher priority): 2

-----------------------------Gantt Chart-----------------------------
Time elapsed 0
READY->  Process 2 | Arrival time: 0 | Burst time: 1 | Priority: 1 | Completion time: 0 | Turn Around Time: 0 | Waiting Time: 0
Time elapsed 1
READY->  Process 5 | Arrival time: 0 | Burst time: 5 | Priority: 2 | Completion time: 0 | Turn Around Time: 0 | Waiting Time: 0
Time elapsed 6
READY->  Process 1 | Arrival time: 0 | Burst time: 10 | Priority: 3 | Completion time: 0 | Turn Around Time: 0 | Waiting Time: 0
Time elapsed 16
READY->  Process 3 | Arrival time: 0 | Burst time: 2 | Priority: 4 | Completion time: 0 | Turn Around Time: 0 | Waiting Time: 0
Time elapsed 18
READY->  Process 4 | Arrival time: 0 | Burst time: 1 | Priority: 5 | Completion time: 0 | Turn Around Time: 0 | Waiting Time: 0
--------------------------------------------------------------

Total completion time is 19

Total turn around time is 60
Average turn around time is 12.0

Total waiting time is 41
Average waiting time is 8.2

Process 2 | Arrival time: 0 | Burst time: 1 | Priority: 1 | Completion time: 1 | Turn Around Time: 1 | Waiting Time: 0
Process 5 | Arrival time: 0 | Burst time: 5 | Priority: 2 | Completion time: 6 | Turn Around Time: 6 | Waiting Time: 1
Process 1 | Arrival time: 0 | Burst time: 10 | Priority: 3 | Completion time: 16 | Turn Around Time: 16 | Waiting Time: 6
Process 3 | Arrival time: 0 | Burst time: 2 | Priority: 4 | Completion time: 18 | Turn Around Time: 18 | Waiting Time: 16
Process 4 | Arrival time: 0 | Burst time: 1 | Priority: 5 | Completion time: 19 | Turn Around Time: 19 | Waiting Time: 18

-----------------------------XXXX-----------------------------

Enter number of processes: 4
Enter arrival time for Process 1: 0
Enter burst time for Process 1: 5
Enter priority for Process 1 (Lower number => Higher priority): 1
Enter arrival time for Process 2: 1
Enter burst time for Process 2: 3
Enter priority for Process 2 (Lower number => Higher priority): 2
Enter arrival time for Process 3: 2
Enter burst time for Process 3: 8
Enter priority for Process 3 (Lower number => Higher priority): 1
Enter arrival time for Process 4: 3
Enter burst time for Process 4: 6
Enter priority for Process 4 (Lower number => Higher priority): 3

-----------------------------Gantt Chart-----------------------------
Time elapsed 0
READY->  Process 1 | Arrival time: 0 | Burst time: 5 | Priority: 1 | Completion time: 0 | Turn Around Time: 0 | Waiting Time: 0
Time elapsed 5
READY->  Process 3 | Arrival time: 2 | Burst time: 8 | Priority: 1 | Completion time: 0 | Turn Around Time: 0 | Waiting Time: 0
Time elapsed 13
READY->  Process 2 | Arrival time: 1 | Burst time: 3 | Priority: 2 | Completion time: 0 | Turn Around Time: 0 | Waiting Time: 0
Time elapsed 16
READY->  Process 4 | Arrival time: 3 | Burst time: 6 | Priority: 3 | Completion time: 0 | Turn Around Time: 0 | Waiting Time: 0
--------------------------------------------------------------

Total completion time is 22

Total turn around time is 50
Average turn around time is 12.5

Total waiting time is 28
Average waiting time is 7.0

Process 1 | Arrival time: 0 | Burst time: 5 | Priority: 1 | Completion time: 5 | Turn Around Time: 5 | Waiting Time: 0
Process 2 | Arrival time: 1 | Burst time: 3 | Priority: 2 | Completion time: 16 | Turn Around Time: 15 | Waiting Time: 12
Process 3 | Arrival time: 2 | Burst time: 8 | Priority: 1 | Completion time: 13 | Turn Around Time: 11 | Waiting Time: 3
Process 4 | Arrival time: 3 | Burst time: 6 | Priority: 3 | Completion time: 22 | Turn Around Time: 19 | Waiting Time: 13

-----------------------------XXXX-----------------------------

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
Time elapsed 1
READY->  Process 2 | Arrival time: 1 | Burst time: 3 | Priority: 1 | Completion time: 0 | Turn Around Time: 0 | Waiting Time: 0
Time elapsed 4
READY->  Process 3 | Arrival time: 2 | Burst time: 6 | Priority: 2 | Completion time: 0 | Turn Around Time: 0 | Waiting Time: 0
Time elapsed 10
READY->  Process 4 | Arrival time: 3 | Burst time: 1 | Priority: 3 | Completion time: 0 | Turn Around Time: 0 | Waiting Time: 0
Time elapsed 11
READY->  Process 1 | Arrival time: 0 | Burst time: 5 | Priority: 4 | Completion time: 1 | Turn Around Time: 0 | Waiting Time: 0
--------------------------------------------------------------

Total completion time is 15

Total turn around time is 34
Average turn around time is 8.5

Total waiting time is 19
Average waiting time is 4.75

Process 1 | Arrival time: 0 | Burst time: 5 | Priority: 4 | Completion time: 15 | Turn Around Time: 15 | Waiting Time: 10
Process 2 | Arrival time: 1 | Burst time: 3 | Priority: 1 | Completion time: 4 | Turn Around Time: 3 | Waiting Time: 0
Process 3 | Arrival time: 2 | Burst time: 6 | Priority: 2 | Completion time: 10 | Turn Around Time: 8 | Waiting Time: 2
Process 4 | Arrival time: 3 | Burst time: 1 | Priority: 3 | Completion time: 11 | Turn Around Time: 8 | Waiting Time: 7
'''
