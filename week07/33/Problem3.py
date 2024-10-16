# max product of three
# array가 주어졌을 때 element 3개 곱한 것 중 최대값 찾기

"""
(풀이 인터넷 참고)
1) 모두 양수 -> arr[-1] * arr[-2] * arr[-3]
2) 모두 음수 -> arr[-1] * arr[-2] * arr[-2] (product도 음수)
3) 양수/음수 섞임
3-1) product 음수이려면 음수 element 오직 하나 (-++)
: arr[-1] * arr[-2] * arr[-3]
3-2) product 양수
: arr[0] * arr[1] * arr[-1] or arr[-1] * arr[-2] * arr[-3]

=> arr[-1] * arr[-2] * arr[-3] 과 arr[0] * arr[1] * arr[-1] 중 큰 것

"""

def solution(arr)->int:
     arr.sort()
     neg = arr[0] * arr[1] * arr[-1]
     pos = arr[-1] * arr[-2] * arr[-3]
     return max(neg, pos)

