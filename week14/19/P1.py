class Solution(object):
    def intToRoman(self, num):
        answer = ""
        roman = {1000:"M", # python 3.5 이하에선 순서가 보장되지 않음
                 900:"CM", 500:"D", 400:"CD", 100:"C",
                 90:"XC", 50:"L", 40:"XL", 10:"X",
                 9:"IX" , 5:"V", 4:"IV", 1:"I"}
        while (num > 0):
            for r in roman:
                if (num >= r):
                    answer += roman[r]
                    num -= r
                    break
        return answer

if __name__ == "__main__":
    result = Solution()
    num = 3749
    print(result.intToRoman(num))
    num = 58
    print(result.intToRoman(num))
    num = 1994
    print(result.intToRoman(num))
