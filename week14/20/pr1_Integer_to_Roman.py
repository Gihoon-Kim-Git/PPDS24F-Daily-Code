class Solution:
    def intToRoman(self, num: int) -> str:
        idx = 0
        ans = ""

        if num >= 1000: idx = 3
        elif num >= 100 : idx = 2
        elif num >= 10 : idx = 1
        else : idx = 0
        # num : 1000~3999
        if idx == 3:
            target = num//1000
            ans += "M"*target
            num -= 1000*target
            idx-=1
        # num : 999~100
        if idx == 2:
            target = num//100
            if target == 4:
                ans += "CD"
            elif target == 9:
                ans += "CM"
            else:
                if target<5:
                    ans += "C"*target
                else:
                    ans += "D"
                    ans += "C"*(target-5)
            num -= 100*target
            idx-=1
        # num : 99~10
        if idx == 1:
            target = num//10
            if target == 4:
                ans += "XL"
            elif target == 9:
                ans += "XC"
            else:
                if target<5:
                    ans += "X"*target
                else:
                    ans += "L"
                    ans += "X"*(target-5)
            num -= 10*target
            idx-=1
        # num : 9~1
        if idx == 0:
            target = num
            if target == 4:
                ans += "IV"
            elif target == 9:
                ans += "IX"
            else:
                if target<5:
                    ans += "I"*target
                else:
                    ans += "V"
                    ans += "I"*(target-5)
            num -= 10*target
            idx-=1

        return ans            
