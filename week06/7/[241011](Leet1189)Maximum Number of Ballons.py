"""문제
text가 주어졌을 때, text가 최대한 많은 'balloon'을 만들도록 하고 싶다. text 안의 character는 최대 한 번만 사용할 수 잇음. 
만들 수 있는 'balloon'의 최대 개수"""

"""문제풀이
    1. dict를 만든다. dict의 key로 b, a, l o, n을 만듦.
    2. text를 순회하면서 dict key 5개에 해당하는 글자일 경우 +1
    3. dict를순회하면서 b,a,n의 개수와 l의 개수//2, o의개수//2 중 min을 찾는다.
        이 min 값이 정답임."""
    

class Solution : 
    def maxNumberOfBalloons(self, text):
        #1
        dic = {}
        need_ch = "balon"
        for i in range(len(need_ch)):
            dic[need_ch[i]] = 0
        #2
        for i in range(len(text)):
            if text[i] in need_ch :
                dic[text[i]] += 1
        #3
        val_num = []
        for key, val in dic.items():
            if key in "lo":
                val_num.append(val//2)
            else :
                val_num.append(val)
        
        return min(val_num)
    
if __name__ == "__main__":
    text = "nlaebolko"  #1
    print(Solution().maxNumberOfBalloons(text))
    
    text = "loonbalxballpoon"  #2
    print(Solution().maxNumberOfBalloons(text))
    
    text = "leetcode" #0
    print(Solution().maxNumberOfBalloons(text))