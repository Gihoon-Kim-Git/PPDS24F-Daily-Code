class Solution:
    def minimumOneBitOperations(self, n: int) -> int:
        def decompose_to_powers_of_two(n):
            # n을 이진수로 표현하고, 값을 2의 제곱수로 분해하여 표현
            binary_representation = bin(n)[:1:-1]  # "0b"를 제거하고 역순으로 뒤집기
            powers_of_two = []
            
            for i, bit in enumerate(binary_representation):
                if bit == '1':
                    powers_of_two.append(2 ** i)
        
            # 내림차순 정렬
            powers_of_two.sort(reverse=True)
            return powers_of_two
        if n == 0:
            return 0
        elif (n & (n-1)) == 0:
            # 2의 제곱수
            return n*2 - 1
        else:
            temp = decompose_to_powers_of_two(n)
            #print(temp)
            result = 0
            for i in range(len(temp)):
                #print(i, (temp[i]*2-1)*((-1)**(i%2)))
                result += (temp[i]*2-1)*((-1)**(i%2))
            return result




#=================
sol = Solution()
print(sol.minimumOneBitOperations(5))