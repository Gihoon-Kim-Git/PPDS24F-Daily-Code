class Solution:
    def flip(self, arr: list[int], k: int) -> list[int]:
        assert 1 <= k <= len(arr)
        return arr[:k][::-1] + arr[k:]

    def argmax(self, arr: list[int], ptr: int) -> int:
        idx = 0
        max_ele = 0
        for i in range(ptr):
            if arr[i] > max_ele:
                idx = i
                max_ele = arr[i]
        return idx

    def helper(self, arr: list[int], ptr: int, k_list: list[int]) -> None:
        # base case : empty arr / sorting is done
        if ptr == 0:
            return

        # recursive case
        argmax_idx = self.argmax(arr, ptr)
        if argmax_idx == ptr - 1:
            return self.helper(arr, ptr-1, k_list)
        else:   # argmax_idx < ptr - 1
            if argmax_idx != 0:
                arr = self.flip(arr, argmax_idx + 1)
                k_list.append(argmax_idx + 1)
            arr = self.flip(arr, ptr)
            k_list.append(ptr)
            return self.helper(arr, ptr-1, k_list)

    def pancakeSort(self, arr: list[int]) -> list[int]:
        k_list = []
        self.helper(arr, len(arr), k_list)
        return k_list
