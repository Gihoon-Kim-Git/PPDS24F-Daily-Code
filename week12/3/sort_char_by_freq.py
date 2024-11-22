def frequencySort(s: str) -> str:

    freqdict = dict()
    for c in s:
        if c not in freqdict:
            freqdict[c] = 1
        else:
            freqdict[c] += 1

    sorted_freqdict = dict(sorted(freqdict.items(), key=lambda item: item[1]))
    rev_keys = list(sorted_freqdict.keys())[::-1]

    ans = ""
    for k in rev_keys:
        ans += k*freqdict[k]
        
    return ans