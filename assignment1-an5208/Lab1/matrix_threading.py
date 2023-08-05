import multiprocessing
import time
import random
import queue
import threading

result = []


def multiplication(n, seed):
    """
    n -- the dimension of a matrix
    seed -- seed value used to generate random numbers
    queue -- where the result will be put in
    Create two nxn matrices and multiply them
    """
    random.seed(seed)
    mat1 = [[None for _ in range(n)] for _ in range(n)]
    mat2 = [[None for _ in range(n)] for _ in range(n)]
    mat3 = [[None for _ in range(n)] for _ in range(n)]

    for i in range(n):
        for j in range(n):
            mat1[i][j] = random.random()
            mat2[i][j] = random.random()

    for i in range(n):
        for j in range(n):
            sum = 0
            for k in range(n):
                sum += mat1[i][k] * mat2[k][j]
            mat3[i][j] = sum
            time.sleep(0.0001)  # Do not remove sleep
    result.append(mat3)

    #queue.put(mat3)


def summation(list_matrices, n):
    """
    Computes the sum of all matrices in list_matrices
    """
    result = []
    for i in range(n):
        row = []
        for j in range(n):
            sum = 0
            for matrix in list_matrices:
                sum += matrix[i][j]
            row.append(sum)
        result.append(row)
    return result


def main():
    dim = 130  # matrix dimension
    matrices = [threading.Thread for _ in range(20)]
    #computed = queue.Queue()

    start = time.perf_counter()
    for i in range(0, 20):
        matrices[i] = threading.Thread(target=multiplication, args=[dim, i])
        # matrices[i] = multiprocessing.Process(target=multiplication, args=[dim, i, computed])
        matrices[i].start()

    for i in range(20):
        matrices[i].join()

    end = time.perf_counter()

    result0 = summation(result, dim)
    print(result0)
    print(f"Elapsed time = {end - start} seconds")


if __name__ == "__main__":
    main()
