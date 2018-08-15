import math
class Solution:
    def repeatedStringMatch(self, A, B):
        """
        :type A: str
        :type B: str
        :rtype: int
        """
        times = int(math.ceil(len(B) / len(A)))
        pre = A * times
        if pre.find(B) != -1:
            return times
        else:
            if (pre + A).find(B) != -1:
                return times + 1
            else:
                return -1


