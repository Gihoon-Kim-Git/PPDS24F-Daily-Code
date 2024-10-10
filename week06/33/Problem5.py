# string을 input으로 받았을 때 string의 알파벳을 한번씩 사용하여
# balloon을 몇 번 만들 수 있는가

class Solution:
    def maxNumberOfBalloons(self, text: str) -> int:
        dict = {'b': 0, 'a': 0, 'l': 0, "o": 0, "n": 0}
        for char in text:
            if char in dict.keys():
                dict[char] += 1

        return min(dict['b'], dict['a'], dict['n'], dict['l'] // 2, dict['o'] // 2)
