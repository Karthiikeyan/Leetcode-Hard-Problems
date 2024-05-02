class Solution:
    def findMaxK(self, nums: List[int]) -> int:
        ans = -1e9
        for i in nums:
            if -i in nums:
                ans = max(ans, i)
        if ans==-1e9:
            return -1
        return ans
        