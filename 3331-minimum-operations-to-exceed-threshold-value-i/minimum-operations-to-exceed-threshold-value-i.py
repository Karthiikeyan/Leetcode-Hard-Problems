class Solution:
    def minOperations(self, nums: List[int], k: int) -> int:
        return next(i for i, num in enumerate(sorted(nums)) if num >= k)    