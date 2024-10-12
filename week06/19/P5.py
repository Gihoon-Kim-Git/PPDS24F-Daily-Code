class Solution:
    def maxNumberOfBalloons(self, text):
        balloon = {'b':0, 'a':0, 'l':0, 'o':0, 'n':0}
        for i in text:
            if i in balloon.keys():
                balloon[i] += 1
        balloon['l'] = int(balloon['l'] / 2)
        balloon['o'] = int(balloon['o'] / 2)
        return min(balloon.values())

if __name__ == "__main__":
    t1 = "nlaebolko"
    t2 = "loonbalxballpoon"
    result = Solution()
    print(result.maxNumberOfBalloons(t1))
    print(result.maxNumberOfBalloons(t2))