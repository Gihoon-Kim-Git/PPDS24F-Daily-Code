# Function to determine if a string of parentheses (multiple types) is properly nested.
# 
# A string S consisting of N characters is considered to be properly nested if any of the following conditions is true:
# - S is empty;
# - S has the form "(U)", "[U]", or "{U}" where U is a properly nested string;
# - S has the form "VW" where V and W are properly nested strings.
# 
# Examples:
# - Given S = "{[()()]}", the function should return 1 (properly nested).
# - Given S = "([)()]", the function should return 0 (not properly nested).
#
# Assumptions:
# - N is an integer within the range [0..200,000];
# - The string S consists of only the characters: '(', '{', '[', ']', '}', and/or ')'.
def solution(S):

    stack = [] # Last In First Out (LIFO)

    bracket_dict = {']':'[', '}':'{', ')':'('}

    for char in S:
        # opening bracket: push to stack
        if char in "({[":
            stack.append(char)

        # closing bracket: remove matching opening bracket
        elif char in ")}]":
            if (not stack) or (stack[-1] != bracket_dict[char]):
                return 0 # not properly nested
            # matching open bracket exist
            stack.pop()

    # check if stack is empty
    if not stack:
        return 1
    else:
        return 0

def test_brackets():
    # Test case 1: Properly nested
    assert solution("{[()()]}") == 1, "Test case 1 failed"
    
    # Test case 2: Not properly nested
    assert solution("([)()]") == 0, "Test case 2 failed"
    
    # Test case 3: Empty string (valid)
    assert solution("") == 1, "Test case 3 failed"
    
    # Test case 4: Single open bracket (invalid)
    assert solution("(") == 0, "Test case 4 failed"
    
    # Test case 5: Single close bracket (invalid)
    assert solution(")") == 0, "Test case 5 failed"
    
    # Test case 6: Nested mixed properly
    assert solution("{{[[(())]]}}") == 1, "Test case 6 failed"
    
    # Test case 7: Not properly nested with mismatched brackets
    assert solution("{[(])}") == 0, "Test case 7 failed"
    
    # Test case 8: Long valid string
    assert solution("()"*100000) == 1, "Test case 8 failed"

    print("All bracket test cases passed.")

# Run the test
test_brackets()
