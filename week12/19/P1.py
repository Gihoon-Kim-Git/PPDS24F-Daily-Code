from collections import Counter

class Solution(object):
    def frequencySort(self, s):
        dict = Counter(s)
        answer = ""
        for key, value in dict.most_common():
            answer += key * value
        return answer

if __name__ == "__main__":
    result = Solution()
    print(result.frequencySort("tree"))
    print(result.frequencySort("cccaaa"))
    print(result.frequencySort("Aabb"))