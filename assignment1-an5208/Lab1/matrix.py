import time
import random


def multiplication(n, seed):
    """
    n -- the dimension of a matrix
    seed -- seed value used to generate random numbers
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

    return mat3


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
    dim = 2  # matrix dimension
    start = time.perf_counter()
    m0 = multiplication(dim, 0)
    m1 = multiplication(dim, 1)
    m2 = multiplication(dim, 2)
    end = time.perf_counter()

    result = summation([m0, m1, m2], dim)
    print(result)
    print(f"Elapsed time = {end - start} seconds")


if __name__ == "__main__":
    main()
