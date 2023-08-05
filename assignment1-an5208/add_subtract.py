import time
import threading

global x

def add():
    global x
    for i in range(10000000):
        lock.acquire()
        x += 1
        lock.release()

def subtract():
    global x
    for i in range(10000000):
        lock.acquire()
        x -= 1
        lock.release()

if __name__ == "__main__":
    global x
    x = 0
    start = time.perf_counter()
    lock =threading.Lock()
    t1 = threading.Thread(target = add)
    t2 = threading.Thread(target = subtract)
    t1.start()
    t2.start()
    t1.join()
    t2.join()

    end = time.perf_counter()
    print(f'final x = {x}')     #0
    print(f'elapsed time = {end - start}')
    
# 1. Measure the elapsed time.
# 2. Run the add and subtract functions concurrently using threading.
# 2. Describe two issues and how would you fix it?
# 3. Do you see any benefit in multi threading? WHy?

#1. originally, the answer is 0 and elapsed time is 2.1608786s.
#2. Using threading and no locks, the answer is wrong and the elapsed time is much higher.
#3. Multi threading is beneficial to programs that are not CPU intensive.
# Programs that are IO bound do not impose a burden on the CPU and actually speeds up the
# process when using multi threading.