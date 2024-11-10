<<<<<<< HEAD
class Solution(object):
    def maxNumberOfBalloons(self, text):
        """
        :type text: str
        :rtype: int
        """
        lst = {}
        for i in text:
            if lst.get(i):
                lst[i] += 1
            else:
                lst[i] = 1
            # print(lst[i])
            # print(i)
        
        if lst.get("b") and lst.get("a") and lst.get("l") and lst.get("o") and lst.get("n"):
            lst["l"] = lst["l"]//2
            lst["o"] = lst["o"]//2
            # print(lst.get("b"))
            return min(lst.get("b"),lst.get("a"),lst.get("l"),lst.get("o"),lst.get("n"))
        else:
            return 0

# ints = Solution()
# print(ints.maxNumberOfBalloons("nlaebolko"))
