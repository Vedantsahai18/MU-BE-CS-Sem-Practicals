from operator import attrgetter

class Process:

	ct = 0
	tat = 0
	wt = 0
	check = False

	def __init__(self, pid, at, bt):
		self.pid = pid
		self.at = at
		self.tempbt = bt
		self.bt = bt

	def atbt(self):
		return f"For Process{self.pid} | Arrival time: {self.at} | Burst time: {self.bt}"

	def __str__(self):
		return f"Process {self.pid} | Arrival time: {self.at} | Burst time: {self.bt} | Completion time: {self.ct} | Turn Around Time: {self.tat} | Waiting Time: {self.wt}"

np = int(input("Enter number of processes: "))

prolist = []

tq = int(input("Enter time quantum: "))

for i in range(0, np):
	a = int(input(f"Enter arrival time for Process {i+1}: "))
	b = int(input(f"Enter burst time for Process {i+1}: "))
	prolist.append(Process(i+1, a, b))


prolist = sorted(prolist, key = attrgetter('at'))

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
	if(readyQ[0].at != 0):
		count = readyQ[0].at
	i = i + 1
	while(k < len(readyQ)): # readyQ will keep decreasing as jobs are removed

		time = 0

		temp = readyQ[k]
		temp.check = True

		print(f"Time elapsed {count}")
		print("READY-> ", temp)

		while(time < tq and temp.tempbt > 0): # Simulation of gantt chart

			time = time + 1
			count = count + 1 # Because of premption, count increments by 1

			for process in prolist:

				if(not process.check and count >= process.at):
					process.check = True
					readyQ.append(process)

			temp.tempbt = temp.tempbt - 1

		temp.ct = count
		k = k + 1

		if(temp.tempbt <= 0):
			pass
		else:
			readyQ.append(temp)

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
Enter number of processes: 6
Enter time quantum: 3
Enter arrival time for Process 1: 5
Enter burst time for Process 1: 5
Enter arrival time for Process 2: 4
Enter burst time for Process 2: 6
Enter arrival time for Process 3: 3
Enter burst time for Process 3: 7
Enter arrival time for Process 4: 1
Enter burst time for Process 4: 9
Enter arrival time for Process 5: 2
Enter burst time for Process 5: 2
Enter arrival time for Process 6: 6
Enter burst time for Process 6: 3

-----------------------------Gantt Chart-----------------------------
Time elapsed 1
READY->  Process 4 | Arrival time: 1 | Burst time: 9 | Completion time: 0 | Turn Around Time: 0 | Waiting Time: 0
Time elapsed 4
READY->  Process 5 | Arrival time: 2 | Burst time: 2 | Completion time: 0 | Turn Around Time: 0 | Waiting Time: 0
Time elapsed 6
READY->  Process 3 | Arrival time: 3 | Burst time: 7 | Completion time: 0 | Turn Around Time: 0 | Waiting Time: 0
Time elapsed 9
READY->  Process 2 | Arrival time: 4 | Burst time: 6 | Completion time: 0 | Turn Around Time: 0 | Waiting Time: 0
Time elapsed 12
READY->  Process 4 | Arrival time: 1 | Burst time: 9 | Completion time: 4 | Turn Around Time: 0 | Waiting Time: 0
Time elapsed 15
READY->  Process 1 | Arrival time: 5 | Burst time: 5 | Completion time: 0 | Turn Around Time: 0 | Waiting Time: 0
Time elapsed 18
READY->  Process 6 | Arrival time: 6 | Burst time: 3 | Completion time: 0 | Turn Around Time: 0 | Waiting Time: 0
Time elapsed 21
READY->  Process 3 | Arrival time: 3 | Burst time: 7 | Completion time: 9 | Turn Around Time: 0 | Waiting Time: 0
Time elapsed 24
READY->  Process 2 | Arrival time: 4 | Burst time: 6 | Completion time: 12 | Turn Around Time: 0 | Waiting Time: 0
Time elapsed 27
READY->  Process 4 | Arrival time: 1 | Burst time: 9 | Completion time: 15 | Turn Around Time: 0 | Waiting Time: 0
Time elapsed 30
READY->  Process 1 | Arrival time: 5 | Burst time: 5 | Completion time: 18 | Turn Around Time: 0 | Waiting Time: 0
Time elapsed 32
READY->  Process 3 | Arrival time: 3 | Burst time: 7 | Completion time: 24 | Turn Around Time: 0 | Waiting Time: 0
--------------------------------------------------------------

Total completion time is 33

Total turn around time is 128
Average turn around time is 21.333333333333332

Total waiting time is 96
Average waiting time is 16.0

Process 4 | Arrival time: 1 | Burst time: 9 | Completion time: 30 | Turn Around Time: 29 | Waiting Time: 20
Process 5 | Arrival time: 2 | Burst time: 2 | Completion time: 6 | Turn Around Time: 4 | Waiting Time: 2
Process 3 | Arrival time: 3 | Burst time: 7 | Completion time: 33 | Turn Around Time: 30 | Waiting Time: 23
Process 2 | Arrival time: 4 | Burst time: 6 | Completion time: 27 | Turn Around Time: 23 | Waiting Time: 17
Process 1 | Arrival time: 5 | Burst time: 5 | Completion time: 32 | Turn Around Time: 27 | Waiting Time: 22
Process 6 | Arrival time: 6 | Burst time: 3 | Completion time: 21 | Turn Around Time: 15 | Waiting Time: 12

-----------------------------XXXX-----------------------------

Enter number of processes: 6
Enter time quantum: 2
Enter arrival time for Process 1: 0
Enter burst time for Process 1: 4
Enter arrival time for Process 2: 1
Enter burst time for Process 2: 5
Enter arrival time for Process 3: 2
Enter burst time for Process 3: 6
Enter arrival time for Process 4: 4
Enter burst time for Process 4: 1
Enter arrival time for Process 5: 6
Enter burst time for Process 5: 3
Enter arrival time for Process 6: 7
Enter burst time for Process 6: 2

-----------------------------Gantt Chart-----------------------------
Time elapsed 0
READY->  Process 1 | Arrival time: 0 | Burst time: 4 | Completion time: 0 | Turn Around Time: 0 | Waiting Time: 0
Time elapsed 2
READY->  Process 2 | Arrival time: 1 | Burst time: 5 | Completion time: 0 | Turn Around Time: 0 | Waiting Time: 0
Time elapsed 4
READY->  Process 3 | Arrival time: 2 | Burst time: 6 | Completion time: 0 | Turn Around Time: 0 | Waiting Time: 0
Time elapsed 6
READY->  Process 1 | Arrival time: 0 | Burst time: 4 | Completion time: 2 | Turn Around Time: 0 | Waiting Time: 0
Time elapsed 8
READY->  Process 4 | Arrival time: 4 | Burst time: 1 | Completion time: 0 | Turn Around Time: 0 | Waiting Time: 0
Time elapsed 9
READY->  Process 2 | Arrival time: 1 | Burst time: 5 | Completion time: 4 | Turn Around Time: 0 | Waiting Time: 0
Time elapsed 11
READY->  Process 5 | Arrival time: 6 | Burst time: 3 | Completion time: 0 | Turn Around Time: 0 | Waiting Time: 0
Time elapsed 13
READY->  Process 3 | Arrival time: 2 | Burst time: 6 | Completion time: 6 | Turn Around Time: 0 | Waiting Time: 0
Time elapsed 15
READY->  Process 6 | Arrival time: 7 | Burst time: 2 | Completion time: 0 | Turn Around Time: 0 | Waiting Time: 0
Time elapsed 17
READY->  Process 2 | Arrival time: 1 | Burst time: 5 | Completion time: 11 | Turn Around Time: 0 | Waiting Time: 0
Time elapsed 18
READY->  Process 5 | Arrival time: 6 | Burst time: 3 | Completion time: 13 | Turn Around Time: 0 | Waiting Time: 0
Time elapsed 19
READY->  Process 3 | Arrival time: 2 | Burst time: 6 | Completion time: 15 | Turn Around Time: 0 | Waiting Time: 0
--------------------------------------------------------------

Total completion time is 21

Total turn around time is 72
Average turn around time is 12.0

Total waiting time is 51
Average waiting time is 8.5

Process 1 | Arrival time: 0 | Burst time: 4 | Completion time: 8 | Turn Around Time: 8 | Waiting Time: 4
Process 2 | Arrival time: 1 | Burst time: 5 | Completion time: 18 | Turn Around Time: 17 | Waiting Time: 12
Process 3 | Arrival time: 2 | Burst time: 6 | Completion time: 21 | Turn Around Time: 19 | Waiting Time: 13
Process 4 | Arrival time: 4 | Burst time: 1 | Completion time: 9 | Turn Around Time: 5 | Waiting Time: 4
Process 5 | Arrival time: 6 | Burst time: 3 | Completion time: 19 | Turn Around Time: 13 | Waiting Time: 10
Process 6 | Arrival time: 7 | Burst time: 2 | Completion time: 17 | Turn Around Time: 10 | Waiting Time: 8
'''
