class Solution:
    def longestCommonPrefix(self, strs):
        """
        :type strs: List[str]
        :rtype: str
        """
        prefix = ''
        for item in zip(*strs):
            c = set(item)
            if len(c) == 1:
                prefix += c.pop()
            else:
                return prefix
        return prefix

