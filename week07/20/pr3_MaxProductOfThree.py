def solution(A):
    # 배열을 오름차순으로 정렬
    A.sort()
    
    # 첫 번째 경우: 가장 큰 세 개의 값의 곱
    max_product1 = A[-1] * A[-2] * A[-3]
    
    # 두 번째 경우: 가장 작은 두 개의 값과 가장 큰 값의 곱
    max_product2 = A[0] * A[1] * A[-1]
    
    # 두 경우 중 최대값을 반환
    return max(max_product1, max_product2)