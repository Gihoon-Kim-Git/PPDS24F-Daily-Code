def maxNumberOfBalloons(text):
    balloon = 0
    dic = {"b":0, "a":0, "l":0, "o":0, "n":0}    # b, a, 2*l, 2*o, n 페어로 단어 하나 만들 수 있음
    chars = dic.keys()

    for c in text:
        if c in chars:
            dic[c] += 1
    
    while dic['b'] >= 1 and dic['a'] >= 1 and dic['l'] >= 2 and dic['o'] >= 2 and dic['n'] >= 1: 
        balloon += 1
        for c in chars:
            if c in ['l','o']:
                dic[c] -= 2
            else:
                dic[c] -= 1

    return balloon

print(maxNumberOfBalloons("leetcode"))