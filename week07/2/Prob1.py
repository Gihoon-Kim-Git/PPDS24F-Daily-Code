class Solution:
    def getRow(self, rowIndex: int) -> List[int]:
        if rowIndex == 0:
            # base case: 0
            return [1]
        elif rowIndex == 1:
            # base case: 1
            return [1, 1]
        else:
            # general case
            result = [1, 1]
            iter = rowIndex - 1
            for _ in range(iter):
                N = len(result)
                # add additional 0
                result.append(0)
                for i in range(N, 0, -1):
                    result[i] += result[i-1]
        return result

            