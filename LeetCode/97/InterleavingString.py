class Solution:
    def __init__(self):
        pass

    def isInterleave(self, s1, s2, s3):
        """
        :type s1: str
        :type s2: str
        :type s3: str
        :rtype: bool
        """
        if s1 == '' and s2 == '':
            return s3 == ''
        if s1 == '':
            return s2 == s3
        if s2 == '':
            return s1 == s3

        rec = [{} for _ in range(s3.__len__())]
        if s1[0] == s3[0]:
            rec[0][1] = 0
        if s2[0] == s3[0]:
            rec[0][0] = 1

        for i in range(1, s3.__len__()):
            for key in rec[i - 1].keys():
                val = rec[i-1].get(key)
                if key != s1.__len__() and s1[key] == s3[i]:
                    rec[i][key + 1] = val
                if val != s2.__len__() and s2[val] == s3[i]:
                    rec[i][key] = val + 1

        for key in rec[s3.__len__() - 1].keys():
            if key == s1.__len__() and rec[s3.__len__() - 1].get(key) == s2.__len__():
                return True

        return False


s = Solution()
print(s.isInterleave("abbbbbbcabbacaacccababaabcccabcacbcaabbbacccaaaaaababbbacbb",
                        "ccaacabbacaccacababbbbabbcacccacccccaabaababacbbacabbbbabc",
                        "cacbabbacbbbabcbaacbbaccacaacaacccabababbbababcccbabcabbaccabcccacccaabbcbcaccccaaaaabaaaaababbbbacbbabacbbacabbbbabc"
                        ))
