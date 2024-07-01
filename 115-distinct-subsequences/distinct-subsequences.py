class Solution:
    def numDistinct(self, s: str, t: str) -> int:
        dp = {}

        def find(i, j):
            if j == len(t):
                return 1
            if i == len(s):
                return 0
            if (i, j) in dp:
                return dp[(i, j)]
            
            if s[i] == t[j]:
                dp[(i, j)] = find(i + 1, j + 1) + find(i + 1, j)
            else:
                dp[(i, j)] = find(i + 1, j)
            
            return dp[(i, j)]
        
        return find(0, 0)