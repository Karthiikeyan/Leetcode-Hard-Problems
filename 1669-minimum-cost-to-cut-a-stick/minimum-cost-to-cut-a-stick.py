class Solution:
    def minCost(self, n: int, cuts: List[int]) -> int:
        dp = {}

        def solve(i, j):
            if j - i == 0:
                return 0
            if (i, j) in dp:
                return dp[(i, j)]
            
            ans = float("inf")
            for c in cuts:
                if i < c < j:
                    ans = min(ans, (j - i) + solve(i, c) + solve(c, j))
            dp[(i, j)] = ans = 0 if ans==float("inf") else ans

            return ans

        return solve(0, n)