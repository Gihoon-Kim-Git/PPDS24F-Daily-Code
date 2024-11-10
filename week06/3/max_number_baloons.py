# Problem: Given a string `text`, find how many times you can form the word "balloon"
# using the characters in `text`. Each character can be used at most once.
#
# To solve this problem:
# - You need to count the occurrences of each character in the word "balloon".
# - The word "balloon" has the following characters: 'b', 'a', 'l', 'o', 'n'.
# - Notice that 'l' and 'o' appear twice in "balloon", so you will need twice as many 'l' and 'o' characters compared to 'b', 'a', and 'n'.
# - The solution is to count how many times the letters in "balloon" can be formed from the given `text`.
# - Return the maximum number of instances of the word "balloon" that can be formed.

# Example 1:
# Input: text = "nlaebolko"
# Output: 1
# Explanation: The string contains exactly the characters to form one "balloon".

# Example 2:
# Input: text = "loonbalxballpoon"
# Output: 2
# Explanation: The string contains enough characters to form two "balloon"s.

# Example 3:
# Input: text = "leetcode"
# Output: 0
# Explanation: There are not enough characters to form "balloon".

# Constraints:
# - 1 <= text.length <= 10^4
# - text consists of lowercase English letters only.

# Approach:
# 1. Count the occurrences of the letters 'b', 'a', 'l', 'o', 'n' in the given text.
# 2. Since 'l' and 'o' appear twice in "balloon", divide the count of 'l' and 'o' by 2.
# 3. The maximum number of "balloon" instances is the minimum of the counts of 'b', 'a', 'l' // 2, 'o' 
def maxNumberOfBalloons(text) -> int:
    balloon_dict = {'b':0, 'a':0, 'l':0, 'o':0, 'n':0}
    for char in text:
        if char in "balon":
            if char in balloon_dict:
                balloon_dict[char] += 1

    # 'l', 'o' value into half
    balloon_dict['l'] //= 2
    balloon_dict['o'] //= 2

    ans = min(balloon_dict.values())  # maximum value
    return ans

# Test cases
def test_maxNumberOfBalloons():
    # Test case 1: Exact match for one "balloon"
    assert maxNumberOfBalloons("nlaebolko") == 1, "Test case 1 failed"

    # Test case 2: Enough characters for two "balloon"s
    assert maxNumberOfBalloons("loonbalxballpoon") == 2, "Test case 2 failed"

    # Test case 3: Not enough characters to form even one "balloon"
    assert maxNumberOfBalloons("leetcode") == 0, "Test case 3 failed"

    # Test case 4: String with extra irrelevant characters
    assert maxNumberOfBalloons("balloonballoon") == 2, "Test case 4 failed"

    # Test case 5: Edge case - empty string
    assert maxNumberOfBalloons("") == 0, "Test case 5 failed"

    # Test case 6: String with exactly enough characters to form one "balloon"
    assert maxNumberOfBalloons("balon") == 0, "Test case 6 failed"  # Missing extra 'l' and 'o' to form "balloon"

    # Test case 7: Large input string with enough characters for many instances of "balloon"
    large_input = "balloon" * 1000
    assert maxNumberOfBalloons(large_input) == 1000, "Test case 7 failed"

    print("All test cases passed!")

# Run the test cases
test_maxNumberOfBalloons()