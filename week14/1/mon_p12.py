class Solution(object):
    def intToRoman(self, num):
        """
        :type num: int
        :rtype: str
        """
        result = ''

        def _add(num_key, result):
            print(num_key, result)
            dct = {
                1:'I',
                5: 'V',
                10: 'X',
                50: 'L',
                100: 'C',
                500: 'D',
                1000: 'M'
            }
            result += dct[num_key]
            return result
        
        str_num = str(num)
        for i in range(len(str_num)):
            decimal = 10**(len(str_num) - i - 1)
            single_num = int(str_num[i]) # single number
            if single_num < 4:
                for _ in range(single_num):
                    result = _add(1*decimal, result)
            elif single_num ==4:
                result = _add(1*decimal, result)
                result = _add(5*decimal, result)
            elif single_num == 5:
                result = _add(5*decimal, result)

            elif (single_num > 5) and (single_num < 9):
                result = _add(5*decimal, result)
                for _ in range(single_num-5):
                    result = _add(1*decimal, result)
            elif single_num == 9:
                result = _add(1, result)
                result = _add(1*(decimal*10), result)
            
        return result
                