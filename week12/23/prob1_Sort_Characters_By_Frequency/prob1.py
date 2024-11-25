'''
Sort Characters By Frequency
'''

from collections import Counter

def frequencySort(s: str) -> str:
    freq = Counter(s)
    sorted_chars = sorted(freq.keys(), key=lambda x: (-freq[x], x))
    return ''.join([char * freq[char] for char in sorted_chars])

# Example usage
s = "tree"
print(frequencySort(s))
