class Solution:
    def __int__(self):
        pass

    def findAndReplacePattern(self, words, pattern):
        """
        :type words: List[str]
        :type pattern: str
        :rtype: List[str]
        """
        ret = []
        for word in words:
            permu = {}
            is_valid = True
            for idx, letter in enumerate(word):
                if permu.get(letter) is None:
                    if pattern[idx] in permu.values():
                        is_valid = Falsexiangqi
                        break
                    permu[letter] = pattern[idx]
                elif permu[letter] != pattern[idx]:
                    is_valid = False
                    break
            if is_valid:
                ret.append(word)

        return ret


s = Solution()
print(s.findAndReplacePattern(["abc","deq","mee","aqq","dkd","ccc"], "abb"))