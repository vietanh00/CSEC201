"""
Suppose that threads need to run in a non-blocking mode.
If the lock is in the locked state, threads need to do some other jobs instead of waiting
until it gets a turn.
More precisely, a thread should either
1. execute the critical section, if the lock is unlocked
2. do something else, if the lock is locked
"""

import threading
import time
import random

x = 0


def task(threadID, lock):
    global x
    acquired = lock.acquire(False)
    if acquired:
        print("thread " + str(threadID) + " is about to acquire the lock.")
        # lock.acquire()
        print("thread " + str(threadID) + " is executing the critical section.")
        x += 1
        lock.release()
    else:
        print("thread " + str(threadID) + " is doing some things.")


def main():
    global x
    thread_nums = 20
    lock = threading.Lock()
    threads = []
    for i in range(thread_nums):
        thread = threading.Thread(target=task, args=[i, lock])
        threads.append(thread)
        thread.start()
    for thread in threads:
        thread.join()

    print(f"final x = {x}")


main()
