def allocation(n, m, allo):
	for i in range(n):
		process = []
		print(f"For Process {i + 1}")
		for j in range(m):
			process.append(int(input(f"Enter number of instances to allocate for resource {j + 1}: ")))
		allo.append(process)

def maximum(n, m, maxi):
	for i in range(n):
		process = []
		print(f"For Process {i + 1}")
		for j in range(m):
			process.append(int(input(f"Enter maximum number of instances needed for resource {j + 1}: ")))
		maxi.append(process)

def cal_need(n, m, maxi, allo, need):
	for i in range(n):
		process = []
		for j in range(m):
			process.append(maxi[i][j] - allo[i][j])
		need.append(process)

def available(m, avail):
    for i in range(m):
        avail.append(int(input(f"Enter number available instances for resource {i + 1}: ")))

def safety(n, m, work, allo, need, finish):
    completed = False
    while(True):
        for i in range(n):
            check = False
            completed = True
            if(not finish[i]):
                completed = False
                for j in range(m):
                    if(need[i][j] <= work[j]):
                        check = True
                    else:
                        check = False
                        break
            if(check):
                for j in range(m):
                    work[j] = work[j] + allo[i][j]
                finish[i] = True
                print(f"Process {i+1}", end = ' --> ')
        if(completed):
            break

def main():
    n = int(input("Enter number of processes: "))
    m = int(input("Enter number of resource types: "))

    avail = []
    allo = []
    maxi = []
    need = []
    finish = [False]*n
    print("\nFOR ALLOCATION")
    allocation(n, m, allo)
    print("\nFOR MAXIMUM REQUIRED")
    maximum(n , m, maxi)
    print("\nFOR AVAILABLE INSTANCES")
    available(m, avail)
    work = avail
    cal_need(n, m, maxi, allo, need)
    print("\nOrder of execution is")
    safety(n, m, work, allo, need, finish)
    print(" ")

main()

'''
Enter number of processes: 4
Enter number of resource types: 3

FOR ALLOCATION
For Process 1
Enter number of instances to allocate for resource 1: 1
Enter number of instances to allocate for resource 2: 0
Enter number of instances to allocate for resource 3: 1
For Process 2
Enter number of instances to allocate for resource 1: 1
Enter number of instances to allocate for resource 2: 1
Enter number of instances to allocate for resource 3: 2
For Process 3
Enter number of instances to allocate for resource 1: 1
Enter number of instances to allocate for resource 2: 0
Enter number of instances to allocate for resource 3: 3
For Process 4
Enter number of instances to allocate for resource 1: 2
Enter number of instances to allocate for resource 2: 0
Enter number of instances to allocate for resource 3: 0

FOR MAXIMUM REQUIRED
For Process 1
Enter maximum number of instances needed for resource 1: 4
Enter maximum number of instances needed for resource 2: 3
Enter maximum number of instances needed for resource 3: 1
For Process 2
Enter maximum number of instances needed for resource 1: 2
Enter maximum number of instances needed for resource 2: 1
Enter maximum number of instances needed for resource 3: 4
For Process 3
Enter maximum number of instances needed for resource 1: 1
Enter maximum number of instances needed for resource 2: 3
Enter maximum number of instances needed for resource 3: 3
For Process 4
Enter maximum number of instances needed for resource 1: 5
Enter maximum number of instances needed for resource 2: 4
Enter maximum number of instances needed for resource 3: 1

FOR AVAILABLE INSTANCES
Enter number available instances for resource 1: 3
Enter number available instances for resource 2: 3
Enter number available instances for resource 3: 0

Order of execution is
Process 1 --> Process 3 --> Process 2 --> Process 4 -->
'''
