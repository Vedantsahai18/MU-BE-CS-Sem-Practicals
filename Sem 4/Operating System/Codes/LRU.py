size = int(input("Enter size of page table: "))
frame = [[None for x in range(2)] for y in range(size)]

miss = 0
hit = 0
i = 0

print("Enter your page reference string")
while True:

    inp = int(input("(Enter -1 to stop): "))
    if(inp == -1):
        break

    for page in frame:

        if(page[0] == None or page[0] != inp):
            check = True
        else:
            check = False
            ind = page
            break

    if(check):
        max = 0

        for page in frame:
            if(page[1] == None):
                rep = page
                break
            else:
                if(page[1] > max):
                    rep = page
                    max = page[1]

        rep[0] = inp
        rep[1] = 0
        miss = miss + 1
        for page in frame:
            if page[0] != None:
                page[1] = page[1] + 1

    else:
        hit = hit + 1
        if(page[1] == None):
            pass
        else:
            for page in frame:
                if page[0] != None:
                    page[1] = page[1] + 1

        ind[1] = 0

    print('\nFrames present')
    for page in frame:
        if page[0] != None:
            print(f"{page[0]}", end = ' ')
    print(f'\nHit ratio is {float(hit)/(hit + miss)*100}%\n')

'''
Enter size of page table: 4
Enter your page reference string
(Enter -1 to stop): 7

Frames present
7
Hit ratio is 0.0%

(Enter -1 to stop): 0

Frames present
7 0
Hit ratio is 0.0%

(Enter -1 to stop): 1

Frames present
7 0 1
Hit ratio is 0.0%

(Enter -1 to stop): 2

Frames present
7 0 1 2
Hit ratio is 0.0%

(Enter -1 to stop): 0

Frames present
7 0 1 2
Hit ratio is 20.0%

(Enter -1 to stop): 3

Frames present
3 0 1 2
Hit ratio is 16.666666666666664%

(Enter -1 to stop): 0

Frames present
3 0 1 2
Hit ratio is 28.57142857142857%

(Enter -1 to stop): 4

Frames present
3 0 4 2
Hit ratio is 25.0%

(Enter -1 to stop): 2

Frames present
3 0 4 2
Hit ratio is 33.33333333333333%

(Enter -1 to stop): 3

Frames present
3 0 4 2
Hit ratio is 40.0%

(Enter -1 to stop): 0

Frames present
3 0 4 2
Hit ratio is 45.45454545454545%

(Enter -1 to stop): 3

Frames present
3 0 4 2
Hit ratio is 50.0%

(Enter -1 to stop): 2

Frames present
3 0 4 2
Hit ratio is 53.84615384615385%

(Enter -1 to stop): 1

Frames present
3 0 1 2
Hit ratio is 50.0%

(Enter -1 to stop): -1
'''
