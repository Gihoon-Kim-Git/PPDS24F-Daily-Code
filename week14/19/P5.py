class Solution(object):
    def pancakeSort(self, arr):
        answer = []
        end = len(arr) - 1
        while (end > 0):
            a = 0
            b = 0
            for i in range(0, end+1):
                if (a < arr[i]):
                    a = arr[i]
                    b = i
            answer.append(b+1)
            arr = arr[b::-1] + arr[b+1:]
            answer.append(end+1)
            arr = arr[end::-1] + arr[end+1:]
            end -= 1
        return answer

if __name__ == "__main__":
    result = Solution()
    arr = [3,2,4,1]
    print(result.pancakeSort(arr))
    arr = [1,2,3]
    print(result.pancakeSort(arr))