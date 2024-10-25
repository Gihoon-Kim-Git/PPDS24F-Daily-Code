# Tie Rope Problem (Greedy)
    # max_ropes_greater_than_k

def max_ropes_greater_than_k(K, A):
    count = 0
    length = 0
    for rope in A:
        length += rope # add length with the previous one.
        if length >= K:
            count += 1
            length = 0
    return count

# Driver Code
if __name__=="__main__":
    A = [1,2,3,4,1,1,3]
    K = 4
    print(max_ropes_greater_than_k(K, A))