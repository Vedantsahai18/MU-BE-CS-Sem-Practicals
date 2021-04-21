import time

channels = 10

timeslot= 418

delay=[]
state=[]
for i in range(channels):
    print(f"Enter delay for channel {i+1}: ")
    delay.append(int(input()))
    state.append(0)

cycles=int(2)
for i in range(cycles):
    cycle= i+1
    t=0
    s=0
    print("--------------")
    print("Cycle ", cycle)
    for channel in range(channels):

        if cycle==1:
            if delay[channel]<10 :
                t = s
                s = s + timeslot
                print(f"Channel {channel+1} has been assigned slot {t} to {s-1}")
                state[channel]=1
            else:
                print(f"Channel {channel+1} has not been assigned any slot")
        else:
            t = s
            s = s + timeslot
            if state[channel]==1:
                print(f"Time slot {t} to {s-1}: idle")
            else:
                print(f"Channel {channel+1} has been assigned slot {t} to {s-1}")
                state[channel]=1
    print("--------------")

'''
Enter delay for channel 1: 
2
Enter delay for channel 2: 
5
Enter delay for channel 3: 
4
Enter delay for channel 4: 
6
Enter delay for channel 5: 
8
Enter delay for channel 6: 
47
Enter delay for channel 7: 
7
Enter delay for channel 8: 
89
Enter delay for channel 9: 
97
Enter delay for channel 10: 
4
--------------
Cycle  1
Channel 1 has been assigned slot 0 to 417
Channel 2 has been assigned slot 418 to 835
Channel 3 has been assigned slot 836 to 1253
Channel 4 has been assigned slot 1254 to 1671
Channel 5 has been assigned slot 1672 to 2089
Channel 6 has not been assigned any slot
Channel 7 has been assigned slot 2090 to 2507
Channel 8 has not been assigned any slot
Channel 9 has not been assigned any slot
Channel 10 has been assigned slot 2508 to 2925
--------------
--------------
Cycle  2
Time slot 0 to 417: idle
Time slot 418 to 835: idle
Time slot 836 to 1253: idle
Time slot 1254 to 1671: idle
Time slot 1672 to 2089: idle
Channel 6 has been assigned slot 2090 to 2507
Time slot 2508 to 2925: idle
Channel 8 has been assigned slot 2926 to 3343
Channel 9 has been assigned slot 3344 to 3761
Time slot 3762 to 4179: idle
--------------
'''