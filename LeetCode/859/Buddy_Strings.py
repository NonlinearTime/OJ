#coding=utf-8
class Solution:
    def __int__(self):
        pass

    def buddyStrings(self, A, B):
        """
        :type A: str
        :type B: str
        :rtype: bool
        """
        if len(A) != len(B):
            return False

        if A == B:
            if len(A) == 1:
                return False
            a = set(A)
            if a.__len__() < len(A):
                return True
            else:
                return False

        cnt = 0
        diff = {}
        for i, ch in enumerate(A):
            if ch != B[i]:
                diff[ch] = 1
                diff[B[i]] = 1
                cnt += 1

        if cnt != 2:
            return False

        if len(diff) != 2:
            return False

        return True


s = Solution()
print(s.buddyStrings('a', 'a'))