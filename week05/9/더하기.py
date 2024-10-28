


def sum_expression_count(n: int) -> int:
    sum_count = [0,1,2,4]

    if n <= 3 :
        return sum_count[n]
    else :
        for _ in range(n-3):
            sum_count.append(sum(sum_count[-3:]))
            sum_count.pop(0)
    
    return sum_count[-1]
    
    

i = int(input())
for _ in range(i):
    n = int(input())
    print(sum_expression_count(n))



if __name__ == '__main__':
    pass