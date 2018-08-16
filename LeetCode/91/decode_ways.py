# coding=utf-8


class Solution:
    def __int__(self):
        pass

    def numDecodings(self, s):
        """
        :type s: str
        :rtype: int
        """

        if s == '' or s[0] == '0':
            return 0
        if len(s) == 1:
            return 1

        rec = [0 for _ in range(len(s) + 1)]
        rec[0] = 1
        rec[1] = 1
        for i in range(2, len(s) + 1):
            # print(i)
            if s[i-1] == '0' and not 1 <= int(s[i-2]) <= 2:
                rec[i] = 0
            elif s[i-1] == '0':
                rec[i] = rec[i - 2]
            elif s[i-2] == '1' or (s[i-2] == '2' and 1 <= int(s[i-1]) <= 6):
                rec[i] = rec[i-1] + rec[i-2]
            else:
                rec[i] = rec[i-1]
        return rec[len(s)]

