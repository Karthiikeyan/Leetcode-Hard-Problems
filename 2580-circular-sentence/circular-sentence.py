class Solution:
    def isCircularSentence(self, s: str) -> bool:
        # s = s.lower()
        l = s.split()
        if(l[0][0] != l[-1][-1]):
            return False
        for i in range(1, len(l)):
            if l[i][0] != l[i-1][-1]:
                return False
        return True