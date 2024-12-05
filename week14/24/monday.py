# integer to Roman

class Solution:
    def intToRoman(self, num: int) -> str:
        roman = {1000: "M", 500: "D", 100: "C", 50: "L", 10: "X", 5: "V", 1: "I"} # roman numerals
        result = []

        # base case
        if num == 0 or num > 3999 or num < 1:
            return ""

        scale = 1

        while num > 0:
            digit = num % 10
            
            if 0 < digit < 4:
                result.append(roman[1*scale] * digit)
            elif digit == 4:
                result.append(roman[1*scale] + roman[5*scale])
            elif 5 <= digit < 9:
                result.append(roman[5*scale] + roman[1*scale] * (digit-5))
            elif digit == 9:
                result.append(roman[1*scale] + roman[10*scale])

            scale *= 10
            num //= 10
        
        result.reverse()
        return "".join(result)

            
if __name__ == "__main__":
    sol = Solution()
    print(sol.intToRoman(1994))
    print(sol.intToRoman(58))
    print(sol.intToRoman(3749))
            
