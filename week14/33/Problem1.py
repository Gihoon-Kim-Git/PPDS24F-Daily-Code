class Solution:
    def intToRoman(self, num: int) -> str:
        # Define the mapping of integers to Roman numerals
        values = [
            1000, 900, 500, 400, 
            100, 90, 50, 40, 
            10, 9, 5, 4, 
            1
        ]
        symbols = [
            "M", "CM", "D", "CD", 
            "C", "XC", "L", "XL", 
            "X", "IX", "V", "IV", 
            "I"
        ]
        
        roman_numeral = ""
        for value, symbol in zip(values, symbols):
            # While the number is greater than or equal to the value
            while num >= value:
                roman_numeral += symbol
                num -= value
        
        return roman_numeral
