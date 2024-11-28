# Sort Characters By Frequency
from collections import Counter

class Solution:
    def frequencySort(self, s: str) -> str:
        # return ''.join(sorted(s, key=lambda x: (-s.count(x), x)))
        # s를 순회하면서 각 문자의 개수를 세고, 그 개수와 문자를 튜플로 만들어서 정렬
        # 람다 함수는 튜플의 첫번째 요소를 기준으로 정렬하고, 같으면 두번째 요소를 기준으로 정렬
        # ''.join()은 정렬된 문자 리스트를 문자열로 변환
        # LeetCode에서는 Time Limit Exceeded가 발생

        return ''.join([k*v for k, v in Counter(s).most_common()])
        # Counter(s)를 만들어서 각 문자의 개수를 세고, most_common()을 통해 개수가 많은 순서대로 정렬
        # [k*v for k, v in Counter(s).most_common()]은 각 문자와 그 문자의 개수를 곱한 리스트를 만듦
        # ''.join()은 리스트를 문자열로 변환
        # 따라서 각 문자를 그 문자의 개수만큼 반복하여 문자열로 변환

