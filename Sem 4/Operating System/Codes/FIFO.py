size = int(input("Enter size of page table: "))
frame = [None]*size

miss = 0
hit = 0
i = 0

print("Enter your page reference string")
while True:

    inp = int(input("(Enter -1 to stop): "))
    if(inp == -1):
        break
    for page in frame:
        if(page != inp):
            check = True
        else:
            check = False
            break

    if(check):
        frame[i] = inp
        i = (i+1)%size
        miss = miss + 1
    else:
        hit = hit + 1
    print('\nFrames present')
    print(*frame, sep = ' ')
    print(f'Hit ratio is {float(hit)/(hit + miss)*100}%\n')

'''
Enter size of page table: 3
Enter your page reference string
(Enter -1 to stop): 1

Frames present
1 None None
Hit ratio is 0.0%

(Enter -1 to stop): 2

Frames present
1 2 None
Hit ratio is 0.0%

(Enter -1 to stop): 3

Frames present
1 2 3
Hit ratio is 0.0%

(Enter -1 to stop): 2

Frames present
1 2 3
Hit ratio is 25.0%

(Enter -1 to stop): 1

Frames present
1 2 3
Hit ratio is 40.0%

(Enter -1 to stop): 5

Frames present
5 2 3
Hit ratio is 33.33333333333333%

(Enter -1 to stop): 2

Frames present
5 2 3
Hit ratio is 42.857142857142854%

(Enter -1 to stop): 1

Frames present
5 1 3
Hit ratio is 37.5%

(Enter -1 to stop): 6

Frames present
5 1 6
Hit ratio is 33.33333333333333%

(Enter -1 to stop): 2

Frames present
2 1 6
Hit ratio is 30.0%

(Enter -1 to stop): 5

Frames present
2 5 6
Hit ratio is 27.27272727272727%

(Enter -1 to stop): 6

Frames present
2 5 6
Hit ratio is 33.33333333333333%

(Enter -1 to stop): 3

Frames present
2 5 3
Hit ratio is 30.76923076923077%

(Enter -1 to stop): 1

Frames present
1 5 3
Hit ratio is 28.57142857142857%

(Enter -1 to stop): 3

Frames present
1 5 3
Hit ratio is 33.33333333333333%

(Enter -1 to stop): 6

Frames present
1 6 3
Hit ratio is 31.25%

(Enter -1 to stop): 1

Frames present
1 6 3
Hit ratio is 35.294117647058826%

(Enter -1 to stop): 2

Frames present
1 6 2
Hit ratio is 33.33333333333333%

(Enter -1 to stop): 4

Frames present
4 6 2
Hit ratio is 31.57894736842105%

(Enter -1 to stop): 3

Frames present
4 3 2
Hit ratio is 30.0%

(Enter -1 to stop): -1
'''
