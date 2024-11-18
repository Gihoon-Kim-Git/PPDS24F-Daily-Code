"""
<Longest Common Prefix>

Write a function to find the longest common prefix string amongst an array of strings.

If there is no common prefix, return an empty string "".
"""

def longestCommonPrefix(strs):
    if not strs: return ""

    prefix = strs[0]    # 첫 단어가 prefix라 가정하고 시작 (안 맞는 거 줄여나감)

    for s in strs[1:]:
        while not s.startswith(prefix):
            prefix = prefix[:-1]     # 맞을 때까지 줄임
            if not prefix:
                return ""

 
    return prefix


print(longestCommonPrefix(["flower","flow","flight"]))  # "fl"
print(longestCommonPrefix(["dog","racecar","car"]))  # ""
