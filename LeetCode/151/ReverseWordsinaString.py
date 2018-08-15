import re
class Solution(object):
    def reverseWords(self, s):
        """
        :type s: str
        :rtype: str
        """
        if s.strip() == '':
            return ''
        s = re.sub(r'[ ]+', ' ', s)
        wl = s.strip().split(" ")
        return ' '.join((wl[::-1]))
