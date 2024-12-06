class Solution:
    def intToRoman(self, num: int) -> str:  # hash table math string 
        value_map = [
            (1000, "M"), (900, "CM"), (500, "D"), (400, "CD"),
            (100, "C"), (90, "XC"), (50, "L"), (40, "XL"),
            (10, "X"), (9, "IX"), (5, "V"), (4, "IV"),
            (1, "I")]
    
        roman_numeral = ""
        for value, symbol in value_map:
            while num >= value:
                roman_numeral += symbol
                num -= value

        return roman_numeral