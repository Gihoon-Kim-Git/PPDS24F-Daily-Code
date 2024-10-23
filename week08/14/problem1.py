# week 08

## Monday. [Tie Ropes](https://app.codility.com/programmers/lessons/16-greedy_algorithms/tie_ropes/)


def solution(K, A):
    if len(A)==1 :
        if A[0]<K: return 0
        else: return 1

    ropes = []
    prev = None
    for i, a in enumerate(A):

        if a>=K:

            ropes.append(i)
            prev = None

        else:

            if prev and prev+a>=K:
                ropes.append(i)
                prev = None
            elif prev:
                prev += a
            else: 
                prev = a


    # write your code in Python 3.6
    return len(ropes)