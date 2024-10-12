class Solution:
    def maxNumberOfBalloons(self, text: str) -> int:
        dic = {'b':0, 'a':0, 'l':0, 'o':0, 'n':0}

        for i in range(len(text)):
            if text[i] in dic:
                dic[text[i]] += 1
        
        dic['l'] = int(dic['l']/2)
        dic['o'] = int(dic['o']/2)
        
        return min(dic.values())