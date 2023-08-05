import time
import multiprocessing


def list_sum(list, queue):  # put the result into the queue
    sum = 0
    for elt in list:
        for i in range(elt):
            sum += 1
    # return sum
    queue.put(sum)


if __name__ == "__main__":
    list1 = [2 * i for i in range(5000)]
    list2 = [2 * i + 1 for i in range(5000)]
    queue = multiprocessing.Queue()

    start = time.perf_counter()
    p1 = multiprocessing.Process(target=list_sum, args=[list1, queue])
    p2 = multiprocessing.Process(target=list_sum, args=[list2, queue])
    p1.start()
    p2.start()
    p1.join()
    p2.join()
    # sum1 = list_sum(list1)
    # sum2 = list_sum(list2)
    while not queue.empty():
        print(queue.get())

    end = time.perf_counter()
    # print("sum1: " + str(sum1))
    # print("sum2: " + str(sum2))
    print(f"elapsed time = {end - start}")

# 1: Measure execution time.
# 2: How would you improve program performance?
# 3: Use Python multiprocessing to run the code in parallel.  

# 1 Execution time is 3.5760274s

# 2 The original program only makes use of 1 interpreter, so it can be improved by multiprocessing.

# 3 Using multiprocessing, the elapsed time is reduced to 2.2989s
