import time
import threading

global x


def add_slow( lock = []):
    global x
    for i in range(10):
        lock.acquire()
        time.sleep(0.1)  # do not use CPU when sleeping
        x += 1
        lock.release()


if __name__ == "__main__":
    global x
    x = 0

    start = time.perf_counter()
    lock = threading.Lock() #Locks are in unlocked state

    # making 100 threads
    num_thread = 10
    threads = []
    for _ in range(num_thread):
        threadA = threading.Thread(target=add_slow , args = [lock])
        threadA.start()
        threads.append(threadA)

    for thread in threads:
        thread.join()

    end = time.perf_counter()
    print(f'final x = {x}')
    print(f'elapsed time = {end - start}')

# 1. Measure execution time.
# 2. Create two threads to run the add_slow function concurrently.
# 3. Is the add_slow function thread safe?

# 1. At least 2 seconds. My actual time was 2.174s.
# 2. The threads provided the answer in over a second.
# 3. Without using locks: The code is thread safe with only 1000 threads.
#                         Higher number of threads may lead to wrong result.
# Using locks : The code is now thread safe.
