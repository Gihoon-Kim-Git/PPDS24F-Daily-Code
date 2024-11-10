# 며칠간의 주가가 array에 주어졌을 때 최대 수익 구하기

"""
time complexity: O(n)
sum이 음수가 될때까지 element를 더한다고 가정
i) 정답 subset이 sum에 포함되어있다면
-> sum의 마지막 element는 음수이므로 정답 subset에 포함 X
ii) sum 이후에 정답 subset이 있다면
-> 정답 subset은 sum의 마지막 이후에 존재 (마지막 element가 음수이므로)
따라서 sum이 음수가 될때까지 더해나가면서 max 찾기
sum이 음수가 되었다면 초기화 후 이어서 max 찾기
"""
def solution(A):
    # Implement your solution here
    if not A or len(A) <= 0:
        return 0
    
    diff = []
    for i in range(len(A)-1):
        diff.append(A[i+1] - A[i])

    ans, lstSum = 0, 0
    for i in range(len(diff)):
        lstSum += diff[i]
        if lstSum > ans:
            ans = lstSum
        elif lstSum < 0:
            lstSum = 0
    return ans


"""
# time complexity: O(nlogn)
# stress test 하나 통과 못함
# array를 두개로 나누었을 때 정답이 있는 부분수열은 
# 1) 왼쪽 2)오른쪽 3) array에 의해 나누어짐 -> 1),2),3) 구해서 비교

def solution(A):
    # Implement your solution here
    if not A or len(A) <= 0:
        return 0
    
    diff = []
    for i in range(len(A)-1):
        diff.append(A[i+1] - A[i])

    def maxSubSum(start, end):
        if start == end:
            return diff[start]
        c = (start+end) // 2
        maxLeft = maxSubSum(start, c)
        maxRight = maxSubSum(c+1, end)

        l_sum, r_sum, l_max, r_max = 0, 0, 0, 0
        
        for i in range(c, start-1, -1):
            l_sum += diff[i]
            if l_max < l_sum:
                l_max = l_sum
        
        for j in range(c+1, end+1):
            r_sum += diff[j]
            if r_max < r_sum:
                r_max = r_sum

        return max(0, maxLeft, maxRight, l_max+r_max)

    return maxSubSum(0, len(diff)-1)
    """