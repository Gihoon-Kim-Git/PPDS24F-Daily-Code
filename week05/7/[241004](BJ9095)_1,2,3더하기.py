"""문제
입력
첫째 줄에 테스트 케이스의 개수 T가 주어진다. 각 테스트 케이스는 한 줄로 이루어져 있고, 정수 n이 주어진다. n은 양수이며 11보다 작다.

출력
각 테스트 케이스마다, n을 1, 2, 3의 합으로 나타내는 방법의 수를 출력한다.
"""

"""문제풀이 : Recursion 활용
    1. input num에서 num-1, num-2, num-3 각각의 조합 수를 다 합하면 되겠다.
    2. num == 1, num==2, num==3인 경우에만 각각 리턴값을 명시.
"""

def num_123_comb(num): # 0< num < 11
    if num == 1 :
        return 1
    if num == 2:
        return 2
    if num == 3:
        return 4
    
    return num_123_comb(num-1) + num_123_comb(num-2) + num_123_comb(num-3)


if __name__ == "__main__":
    n = int(input())
    for i in range(n):
        num = int(input())
        print(num_123_comb(num))
