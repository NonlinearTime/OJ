#coding=utf-8

import re


class Solution:

    def isPalindrome(self, s):
        """
        :type s: str
        :rtype: bool
        """
        str = "".join(list(filter(lambda x: x.isalnum(), s))).lower()
        return str == str[::-1]

