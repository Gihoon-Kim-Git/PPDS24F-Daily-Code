class Solution:
    def minimumOneBitOperations(self, n: int) -> int:
        # memo for 'make_leading1_at_i'
        self.memo = dict()

        bitlist = self.convert_int_to_bitlist(n)
        # print(bitlist)
        return self.helper(bitlist)
    
    def helper(self, bitlist: list[int]) -> int:
        if len(bitlist) == 0:
            # CASE 1 : do nothing
            return 0
        elif len(bitlist) == 1:
            # CASE 2 : delete the head
            return self.delete_leading1_at_i(bitlist[0])
        elif len(bitlist) == 2:
            # CASE 3 : upgrade the vice / delete the head / CASE 2
            cnt = 0
            cnt += self.upgrade_leading1_at_i_to_j(bitlist[0], bitlist[1]-1)
            cnt += 1
            cnt += self.delete_leading1_at_i(bitlist[1]-1)
            return cnt
        else:
            # CASE 4 : delete all tails except vice / CASE 3
            return self.helper(bitlist[:-2]) + self.helper(bitlist[-2:])

    def convert_int_to_bitlist(self, n: int) -> list[int]:
        bitlist = []
        i = 0
        while n > 0:
            if n % 2 == 1:
                bitlist.append(i)
            i += 1
            n = n >> 1
        return bitlist
    
    def make_leading1_at_i(self, i: int):
        if i == 0:
            return 1
        elif i in self.memo:
            return self.memo[i]
        else:
            # assert i > 0
            cnt = self.make_leading1_at_i(i-1) + 1 + self.delete_leading1_at_i(i-1)
            self.memo[i] = cnt
            return cnt
    
    # def upgrade_leading1_at_i(self, i: int):
    #     # assert i >= 0
    #     return self.make_leading1_at_i(i+1) - self.make_leading1_at_i(i)
    
    def upgrade_leading1_at_i_to_j(self, i: int, j: int):
        # assert i <= j
        return self.make_leading1_at_i(j) - self.make_leading1_at_i(i)

    def downgrade_leading1_at_i(self, i: int):
        if i == 0:
            return 1
        else:
            # assert i > 0
            return self.make_leading1_at_i(i-1) + 1

    def delete_leading1_at_i(self, i: int):
        # assert i >= 0
        cnt = 0
        for k in range(i+1):
            cnt += self.downgrade_leading1_at_i(k)
        return cnt
