"""
<Integer to Roman>
"""

def intToRoman(num):
    roman_symbols = [
        ("M", 1000), ("CM", 900), ("D", 500), ("CD", 400),
        ("C", 100), ("XC", 90), ("L", 50), ("XL", 40),
        ("X", 10), ("IX", 9), ("V", 5), ("IV", 4),
        ("I", 1)
    ]
    
    result = ""
    
    # Iterate through each Roman numeral symbol and value
    for symbol, value in roman_symbols:
        # Append the Roman symbol while the number is greater than or equal to the value
        while num >= value:
            result += symbol
            num -= value
            
    return result

print(intToRoman(1987))  # Output: MCMLXXXVII
print(intToRoman(3999))  # Output: MMMCMXCIX
print(intToRoman(44))    # Output: XLIV