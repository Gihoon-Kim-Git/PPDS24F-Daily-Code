"""
<Sort Characters By Frequency>

Given a string s, sort it in decreasing order based on the frequency of the characters. 
The frequency of a character is the number of times it appears in the string.

Return the sorted string. If there are multiple answers, return any of them.
"""

def frequencySort(s):
    count = {}
    for c in s:
        if c not in count: 
            count[c] = 1
        else:
            count[c] += 1
    
    sorted_dict = dict(sorted(count.items(), key=lambda item: item[1]))
    #print(sorted_dict)
    res = ""
    for k, v in sorted_dict.items():
        res += k * v


    return res


print(frequencySort("tree"))   # eert
print(frequencySort("cccaaa")) 
print(frequencySort("Aabb"))   

