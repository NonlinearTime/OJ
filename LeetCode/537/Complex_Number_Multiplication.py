import re


class Solution:
    def complexNumberMultiply(self, a, b):
        """
        :type a: str
        :type b: str
        :rtype: str
        """
        la = a.split("+")
        lb = b.split("+")
        a_first = int(la[0])
        a_last = int(la[1].split('i')[0])
        b_first = int(lb[0])
        b_last = int(lb[1].split('i')[0])

        res_first = a_first * b_first - a_last * b_last
        res_last = a_first * b_last + a_last * b_first
        res = str(res_first) + '+' + str(res_last) + 'i'
        return res
