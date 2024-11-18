from collections import List 

class Solution:
    def longestCommonPrefix(self, strs: List[str]) -> str:
        if not strs:
            return ""

    # Initialize the prefix to the first string
        prefix = strs[0]

        # Loop through the string array starting from the second string
        for s in strs[1:]:
            # Reduce the prefix length until it matches the start of `s`
            while not s.startswith(prefix):
                prefix = prefix[:-1]
                if not prefix:
                    return ""

        return prefix