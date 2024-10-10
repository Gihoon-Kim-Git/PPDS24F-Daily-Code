def reverseBits(n):
    n = bin(n)[2:].zfill(32)     # 32자리로 강제
    res = list(n)
    
    sum = 0
    for i in range(32):
        sum += 2**i * int(res[i])    # 앞에서부터 2^i 승으로 곱하면 뒤집는 꼴

    return sum

print(reverseBits(43261596))
