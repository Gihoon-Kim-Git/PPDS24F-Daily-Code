"""Given a string s, sort it in decreasing order based on the frequency of the characters. The frequency of a character is the number of times it appears in the string.

Return the sorted string. If there are multiple answers, return any of them.

Constraints:
    1 <= s.length <= 5 * 105
    s consists of uppercase and lowercase English letters and digits.
"""
"""새로이 알게 된 것 
    ★ Dictionary 정렬
        - Dictionary 자체에는 sort()가 없음.
        - Key 기준 정렬 :
            my_dict = {'banana': 3, 'apple': 2, 'pear': 1}
            sorted_dict = {key: my_dict[key] for key in sorted(my_dict)}
        - Val 기준 정렬 : 
            sorted_dict = {k:v for k, v in sorted(my_dict.items(), key = lambda item:item[1])}    
"""




#%% 다른사람 풀이 :https://leetcode.com/problems/sort-characters-by-frequency/solutions/4689154/beats-100-users-c-java-python-javascript-2-approaches-explained/
"""이제 Counter, itertools를 사용하자!!!! 이 문제를 Counter로 풀면 굉장히 빠르다."""
""" Counter에 대한 함수 중 .most_common() 함수가 있음 : 이거는 가장 빈번한 것부터 순서대로 가져오는거."""


#%%
##---------------[Second Trial : 통과 ] : dictionary sort 함수 사용)------------------------------------------------------

class Solution():
    def frequencySort(self, s)->str:
        char_count = {}
        for c in s :
            if c in char_count :
                char_count[c] += 1
            else :
                char_count[c] = 1
        
        sorted_dic = {k:v for k, v in sorted(char_count.items(), key = lambda item:item[1], reverse = True)}
        answer = ""
        print(sorted_dic)
        for key, val in sorted_dic.items() :
            answer += val*key
        
        
        return answer

    
sol1 = Solution()
print(sol1.frequencySort("Aabb")) #bbAa


#%%

##------------------------[First Trial : 통과]----------------------------------------------------------------------------------------------

"""아이디어
    1. dictionary를 만든다. (대, 소문자따로)
    2. 단어를 순회하면서 각 글자는 key, 횟수는 val로 update.
    3. dictionary를 val을 기준으로 정렬할 수 있나???
        만약 안되면 dictionary를 하나 만들어서, 이번에는 횟수를 key로, val로는 해당하는 글자를 []에 넣도록 함.
        동시에 val만 들어있는 set을 만들고.
        그 set의 요소들을 list로 만들어서 sort. (높은 횟수부터 차례로 char를 출력하기 위함.)
    4. 새로 만든 dict에서 , answer에 append.
"""

class Solution():
    def frequencySort(self, s)->str:
        char_count = {}
        for c in s :
            if c in char_count :
                char_count[c] += 1
            else :
                char_count[c] = 1
        
        count_char = {}
        counts = set()
        for ch, count in char_count.items() :
            counts.add(count)
            if count not in count_char :
                count_char[count] = [ch]
            else :
                count_char[count].append(ch)

        counts_list = [count for count in counts]
        counts_list.sort(reverse=True)    
                        
        answer = ""
        
        for counter in counts_list:
            for key, val in count_char.items() :
                if key == counter :
                    for v in val :
                        answer += (v*key)
        
        return answer
    
    
sol1 = Solution()
sol1.frequencySort("Aabb") #bbAa
        
        
        

# %%
