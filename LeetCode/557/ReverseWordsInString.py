class Solution:
    def __init__(self):
        pass

    def reverseWords(self, s):
        """
        :type s: str
        :rtype: str
        """
        words = s.split(' ')
        print(words)
        res = ' '.join([item[::-1] for item in words])
        print(res)
        return res


s = Solution()
s.reverseWords("Let's take LeetCode contest")

