# sum이 K 이상인 solution 최대한 많이 만들기
# set이 많으려면 한 set에는 최소한의 원소만 담아야 함
# greedy하게 담다가 넘으면 바로 자르기

def solution(K,A):
    count = 0
    subset_sum = 0
    for i in range(len(A)):
        subset_sum += A[i]
        if subset_sum >= K:
            subset_sum = 0    
            count += 1
            
    return count




def run_tests():
    # # Test case 1: Example case from the problem statement
    # K = 4
    # A = [1, 2, 3, 4, 1, 1, 3]
    # print("Test case 1:", solution(K, A))  # Expected output: 3

    # # Test case 2: Only one rope, already greater than or equal to K
    # K = 5
    # A = [6]
    # print("Test case 2:", solution(K, A))  # Expected output: 1

    # # Test case 3: Only one rope, less than K
    # K = 5
    # A = [3]
    # print("Test case 3:", solution(K, A))  # Expected output: 0

    # # Test case 4: All ropes are individually greater than or equal to K
    # K = 2
    # A = [3, 4, 5, 6]
    # print("Test case 4:", solution(K, A))  # Expected output: 4

    # Test case 5: Ropes need to be combined to exceed K
    K = 10
    A = [5, 3, 2, 6, 1, 4, 3]
    print("Test case 5:", solution(K, A))  # Expected output: 2 (5+3+2=10 and 6+1+4=11)

    # Test case 6: Maximum possible input size with smallest values
    K = 1000000000
    A = [1] * 100000  # All values are 1
    print("Test case 6:", solution(K, A))  # Expected output: 0 (no ropes can reach K)

    # Test case 7: Large K value but ropes are equal to K
    K = 1000000000
    A = [1000000000] * 10  # All values are exactly K
    print("Test case 7:", solution(K, A))  # Expected output: 10

    # Test case 8: Large array, no need to combine ropes
    K = 1
    A = [1] * 100000  # Each rope is 1 and meets K requirement
    print("Test case 8:", solution(K, A))  # Expected output: 100000

    # Test case 9: K is larger than the sum of all ropes
    K = 100
    A = [5, 6, 7, 8]
    print("Test case 9:", solution(K, A))  # Expected output: 0

    # Test case 10: Edge case with smallest input
    K = 1
    A = [1]
    print("Test case 10:", solution(K, A))  # Expected output: 1

# Run all test cases
run_tests()
