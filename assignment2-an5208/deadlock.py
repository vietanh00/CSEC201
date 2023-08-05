import threading
import threading

x = 0


def task(lock1, lock2, count):
    global x
    for i in range(count):
        # Assume that a thread can update the x value
        # only after both locks have been acquired.
        while True:
            lock1.acquire()
            acquired = lock2.acquire(False)
            if acquired:
                x += 1
                lock1.release()
                lock2.release()
                break  # stop this loop when the task is done
            else:  # giving up lock 1 so that other threads can do stuff
                lock1.release()


def main():
    global x
    count = 1000000
    lock1 = threading.Lock()
    lock2 = threading.Lock()
    T1 = threading.Thread(target=task, args=(lock1, lock2, count))
    T2 = threading.Thread(target=task, args=(lock2, lock1, count))
    T1.start()
    T2.start()
    T1.join()
    T2.join()
    print(f"x = {x}")


main()
