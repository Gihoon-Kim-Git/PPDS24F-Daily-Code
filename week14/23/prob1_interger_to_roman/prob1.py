def int_to_roman(num):
    """
    Convert an integer to a Roman numeral.
    """
    # Define Roman numeral symbols and their values
    value_to_roman = [
        (1000, 'M'),
        (900, 'CM'),
        (500, 'D'),
        (400, 'CD'),
        (100, 'C'),
        (90, 'XC'),
        (50, 'L'),
        (40, 'XL'),
        (10, 'X'),
        (9, 'IX'),
        (5, 'V'),
        (4, 'IV'),
        (1, 'I'),
    ]

    # Initialize the result as an empty string
    roman_num = ""

    # Iterate over the value-symbol pairs
    for value, roman_symbol in value_to_roman:
        while num >= value:
            roman_num += roman_symbol
            num -= value

    return roman_num

print(int_to_roman(1994))  # Output: MCMXCIV
print(int_to_roman(58))    # Output: LVIII
