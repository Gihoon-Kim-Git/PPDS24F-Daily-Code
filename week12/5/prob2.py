# Definition (.) :
# - We use a.b to represent the concatenation of non-negative integers a and b .
# 
# Property (transitivity) :
# - Let a, b, and c be non-negative integers. If a.b > b.a and b.c > c.b , we have a.c > c.a .
#
# Definition (order; a > b) :
# - Let a and b be non-negative integers. a > b if a.b > b.a .
# 
# Lemma :
# - All permutation of "abcd...z" are 'smaller or equal' than "abcd...z".
# 
# Theorem :
# - Let a>b>c>d>...>z. Then the largest number is "abcd...z".

class Solution:
    def largestNumber(self, nums: list[int]) -> str:
        answer = ""
        choosed = [False for _ in range(len(nums))]
        for _ in range(len(nums)):
            argmax = -1
            for i in range(len(nums)):
                if choosed[i]:
                    continue
                else:
                    if argmax == -1:
                        argmax = i
                    elif self.compare(nums[i], nums[argmax]):
                        argmax = i
            choosed[argmax] = True
            answer += str(nums[argmax])
        return str(int(answer))

    def compare(self, num1: int, num2: int) -> bool:
        return int(str(num1) + str(num2)) > int(str(num2) + str(num1))
