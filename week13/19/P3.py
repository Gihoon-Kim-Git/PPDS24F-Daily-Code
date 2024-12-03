class Solution(object):
    def kWeakestRows(self, mat, k):
        array = {}
        answer = []
        for i in range(len(mat)):
            array[i] = sum(mat[i])
        array = sorted(array.items(), key=lambda x:x[1])
        for j in range(k):
            answer.append(array[j][0])
        return answer

if __name__ == "__main__":
    result = Solution()
    mat = [[1,1,0,0,0],
           [1,1,1,1,0],
           [1,0,0,0,0],
           [1,1,0,0,0],
           [1,1,1,1,1]]
    print(result.kWeakestRows(mat, 3))
    mat = [[1,0,0,0],
           [1,1,1,1],
           [1,0,0,0],
           [1,0,0,0]]
    print(result.kWeakestRows(mat, 2))