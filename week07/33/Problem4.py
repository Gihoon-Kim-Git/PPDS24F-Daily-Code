# 0 이상 M 이하의 수로 구성된 array가 주어졌을 때,
# array를 K개의 블록으로 나누는데
# 각 블록의 합의 최댓값을 large sum이라 할 때 large sum의 최소값 구하기 

"""
(풀이 GPT 참고)
"""
def solution(arr, k:int, m:int) -> int:
    low = max(arr)    # 최소 large sum 값 (k=len(arr))
    high = sum(arr)   # 최대 large sum 값 (k=1)

    # large sum이 max_sum 이하가 될 수 있는지 확인
    def is_valid(max_sum):
        # empty block 하나로 시작
        curr = 0
        blocks = 1
        for num in arr:
            # max_sum보다 커지기 전까지 block에 숫자 더하기
            if curr + num <= max_sum:
                curr += num
            # max_sum보다 커지면 블록 하나 추가
            else:
                blocks += 1
                curr = num
                # block 수가 k보다 커지면 X
                # block 수가 k보다 작으면 나머지는 empty block으로 두면 되니까 ㄱㅊ
                if blocks > k:
                    return False
        return True
    
    # max_sum을 binary search
    while low <= high:
        mid = (low + high) // 2
        # mid를 max sum으로 할 수 있으면 더 작은 숫자로
        if is_valid(mid):
            high = mid - 1
        # mid를 max sum으로 할 수 없으면 숫자 키우기
        else:
            low = mid + 1
    return low