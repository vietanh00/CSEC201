import threading
import time
import random
import sys

go = True
philosophers_num = 5


class Philosopher(threading.Thread):
    def __init__(self, threadID, left_fork, right_fork):
        threading.Thread.__init__(self)
        self.id = threadID
        self.left_fork = left_fork
        self.right_fork = right_fork

    def run(self):
        global go
        while go:
            print(f"philosopher {self.id} is thinking...")
            while True:
                self.left_fork.acquire()
                print(f"philosopher {self.id} picks up left fork.")
                acquired = self.right_fork.acquire(False)
                if acquired:
                    print(f"philosopher {self.id} picks up right fork.")
                    print(f"philosopher {self.id} is eating...")
                    time.sleep(random.random())

                    self.left_fork.release()
                    print(f"philosopher {self.id} puts down left fork.")
                    self.right_fork.release()
                    print(f"philosopher {self.id} puts down right fork and is done eating for now.")
                    break  # stop this loop when done eating
                else:  # giving up left fork so that other philosophers may eat
                    print(f"philosopher {self.id} gets bullied and puts down left fork.")
                    self.left_fork.release()
                    time.sleep(random.random())


def main():
    global philosophers_num
    global go
    philosophers_num = int(sys.argv[1])
    if philosophers_num <= 1:
        print("You have too few philosophers! There should be at least 2.")
    else:
        threads = []
        locks = [threading.Lock() for _ in range(philosophers_num)]

        for i in range(philosophers_num):
            thread = Philosopher(i, locks[i], locks[(i + 1) % philosophers_num])
            threads.append(thread)

        for i in range(philosophers_num):
            threads[i].start()

        time.sleep(2)
        go = False


main()
