class Solution:
    def maxNumberOfBalloons(self, text: str) -> int:
        char_dict = {'b': 0, 'a': 0, 'l': 0, 'o': 0, 'n': 0}
        for c in text:
            if c not in char_dict:
                char_dict[c] = 1
            else:
                char_dict[c] += 1
        char_dict['l'] = char_dict['l'] // 2
        char_dict['o'] = char_dict['o'] // 2

        return min(char_dict['b'], char_dict['a'], char_dict['l'], char_dict['o'], char_dict['n'])
