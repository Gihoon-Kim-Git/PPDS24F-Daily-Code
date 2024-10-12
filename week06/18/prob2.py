import time


def solution(A):
    # Every step, you can take the step between [K-6]~[K-1] before stepping [K].
    # Suppose we have the max for [K-6], ..., [K-1].
    # We add the max([K-6], ... , [K-1]).
    
    max_sum_dict = {0:A[0], 1: A[0]+A[1]}
        
    for i in range(2, len(A)):
        max_prev = max_sum_dict[i-1]
        for j in range(2,7):
            if (i-j) >= 0:
                max_prev = max(max_sum_dict[i-j], max_prev) 
                
        max_sum_dict[i] = max_prev + A[i]
    
    return max_sum_dict[len(A)-1]
    

def main():
    ex1 = [1, -2, 0, 9, -1, -2]
    ex2 = [4, 10, -3, -7, -9, -4, -8, -5, 8, -2, 7, -1, 4, -5]
    
    time1 = time.time()
    print(solution(ex1))
    time2 = time.time()

    ex1_time = time2 - time1
    print(f"Elapsed time for list length 6: {ex1_time:.6f} seconds")

    time3 = time.time()
    print(solution(ex2))
    time4 = time.time()
    
    ex2_time = time4 - time3
    print(f"Elapsed time for list length 14: {ex2_time:.6f} seconds")

if __name__ == '__main__':
    main()