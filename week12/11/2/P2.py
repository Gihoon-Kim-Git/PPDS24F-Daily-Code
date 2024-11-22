from functools import cmp_to_key

class Solution:
    def largestNumber(self, nums: List[int]) -> str:
        # 사용자 정의 비교 함수
        def compare(x, y):
            if x + y > y + x:
                return -1  # x + y가 더 크면 x가 앞에
            elif x + y < y + x:
                return 1   # y + x가 더 크면 y가 앞에
            else:
                return 0   

        # 숫자를 문자열로 변환하여 정렬
        nums = list(map(str, nums))
        nums.sort(key=cmp_to_key(compare))

        # 결과 결합
        result = "".join(nums)

        # "0"만 포함된 경우 처리
        return "0" if result[0] == "0" else result


    def largestNumber(self, nums:List[int]) -> str:
        nums = list(map(str,nums))

        for i in range(1,len(nums)):
            pivot = nums[i]
            j = i - 1
            # 한칸씩 내리면서 들어가야할 자리를 찾음
            while j >= 0 and nums[j] + pivot < pivot + nums[j]:
                nums[j + 1] = nums[j]
                j -= 1
            nums[j + 1] = pivot
        
        result = "".join(nums)
        return "0" if result[0] == "0" else result
