# Problem Summary:
# Given an array A of N ropes, where each element represents the length of a rope, 
# and an integer K, the goal is to tie adjacent ropes together in such a way that 
# the number of ropes with a length greater than or equal to K is maximized.
# Two adjacent ropes can be tied together, and the resulting rope's length is the 
# sum of their lengths. The problem is to find the maximum number of ropes that 
# can be tied to achieve lengths greater than or equal to K.

def solution(K: int, A):
    
    ans = 0 # number of ropes w. length >= K

    curr_length = 0 # accumulated length of current tied rope

    for rope in A:
        curr_length += rope

        if curr_length >= K: # meets required length
            ans += 1

            # RESET CURRENT LENGTH (GREEDY APPROACH)
            curr_length = 0 # consider next ropes separately
            # form smallest possible valid rope segment before adding next rope
            # maximize number of segments: remaining ropes are carrired forward
    
    return ans

# Example
K = 4
A = [1, 2, 3, 4, 1, 1, 3]
result = solution(K, A)
print(result)
# $ python tie_ropes.py
# 3