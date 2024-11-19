class Solution(object):
    def frequencySort(self, s):
        """
        :type s: str
        :rtype: str
        """
        count_freq = {}
        sort_freq = {}

        for single in s:
            if single not in count_freq.keys():
                count_freq[single] = 1
            else:
                count_freq[single] += 1
        for str_key in count_freq.keys():
            cnt_key = count_freq[str_key]
            if cnt_key not in sort_freq.keys():
                sort_freq[cnt_key] = [str_key]
            else:
                sort_freq[cnt_key].append(str_key)
        
        result = ''
        for cnt_key in range(len(s), 0, -1):
            if cnt_key in sort_freq.keys():
                for ss in sort_freq[cnt_key]:
                    result += (cnt_key * ss)
        return result
            
                
        
        