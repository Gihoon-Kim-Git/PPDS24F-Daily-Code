from typing import List

class Solution:
    def pancakeSort(self, arr: List[int]) -> List[int]:
        res = []
        n = len(arr)
        for size in range(n, 1, -1):
            # 제일 큰 숫자의 인덱스를 찾고, 맨 앞이 아니라면 pancake sorting 수행
            # arr은 1 to arr.length의 permutation이므로, max_num == size
            max_num = size
            idx = arr.index(max_num)
            if idx != size - 1:
                if idx != 0:
                    res.append(idx + 1)
                    arr[:idx+1] = arr[:idx+1][::-1]
                # 해당 array를 다시 맨 뒤로 뒤집어 정렬
                res.append(size)
                arr[:size] = arr[:size][::-1]
        return res