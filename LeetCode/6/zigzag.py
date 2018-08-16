import math


class Solution:
    def __int__(self):
        pass

    def convert(self, s, numRows):
        """
        :type s: str
        :type numRows: int
        :rtype: str
        """
        if s == '':
            return s
        if len(s) == 1:
            return s
        if numRows == 1:
            return s

        part_ele_nums = 2 * numRows - 2
        part_col_nums = numRows - 1
        part_nums = int(math.ceil(len(s) / part_ele_nums))
        cols = part_col_nums * part_nums
        # print(cols)
        rec = [([''] * cols) for _ in range(numRows)]
        # for i in range(numRows):
        #     print(rec[i])

        pos = [0, 0]
        is_down = True

        for i in range(len(s)):
            rec[pos[0]][pos[1]] = s[i]
            if is_down:
                pos[0] += 1
            else:
                pos[0] -= 1
                pos[1] += 1
            if pos[0] == numRows - 1:
                is_down = False
            if pos[0] == 0:
                is_down = True
        # for i in range(numRows):
        #     print(rec[i])
        ret = ''
        for i in range(numRows):
            for item in rec[i]:
                ret += item
        # print(ret)
        return ret






