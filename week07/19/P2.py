class Solution:
    def quickSort(self, arr):
        low = []
        high = []
        if (arr == []):
            return []
        pivot = arr[0]
        for j in arr[1:]:
            if (j <= pivot):
                low.append(j)
            elif (j > pivot):
                high.append(j)
        low = self.quickSort(low)
        high = self.quickSort(high)
        return low + [pivot] + high

if __name__ == "__main__":
    arr = [2, 1, 6, 10, 4, 1, 3, 9, 7]
    result = Solution()
    print(result.quickSort(arr))