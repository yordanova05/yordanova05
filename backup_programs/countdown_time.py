import time
my_time = int(input("Enter time in seconds: "))
# for x in reversed(range(0,my_time)):
#     print(x)
#     time.sleep(1)
# time.sleep(3)
# print("Locked up!")           

for x in range(my_time,0,-1):
    seconds = x%60
    minets = int(x/60)%60
    hours = int(x/3600)    
    print(f"{hours:02}:{minets:2}:{seconds:02}")
    time.sleep(1)
print("Times UP")