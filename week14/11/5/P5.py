class Solution:
    def pancakeSort(self, arr: List[int]) -> List[int]:
        return self.helper([], arr)
    
    def helper(self, result, arr):
        if len(arr) == 1: 
            return result
        
        b = arr.index(max(arr)) 
        if b != len(arr) - 1:
            if b != 0: 
                result.append(b + 1)
                arr = arr[:b+1][::-1] + arr[b+1:]  # 첫 번째 플립

            result.append(len(arr))  # 최대값을 올바른 위치로 이동
            arr = arr[::-1]  # 두 번째 플립

        return self.helper(result, arr[:-1])  # 배열 크기 축소 후 재귀 호출