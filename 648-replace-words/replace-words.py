class Solution:
    def replaceWords(self, dictionary: List[str], sentence: str) -> str:
        l = list(sentence.split(" "))
        for i in range(len(l)):
            for dic in dictionary:
                val = l[i].find(dic)
                if val==0:
                    l[i] = dic
        return " ".join(l) 

        