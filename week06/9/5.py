

class Solution:
    def maxNumberOfBalloons(self, text: str) -> int:
        balloon_map = {'b':0, 'a':0, 'l':0, 'o':0, 'n':0}
        for s in text:
            if s in balloon_map:
                balloon_map[s] +=1
        
        for i in ['l', 'o']:
            balloon_map[i] = balloon_map[i]//2
        
        return min(balloon_map.values())
    
    

if __name__ == '__main__':
    pass
        