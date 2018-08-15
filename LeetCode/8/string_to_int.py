class Solution:
    def __int__(self):
        pass

    def myAtoi(self, str):
        """
        :type str: str
        :rtype: int
        """
        if str.strip() == '' or str.strip() == '-' or str.strip() == '+':
            return 0
        fst = str.strip().split(' ')[0]
        print(str.strip().split(' '))
        if not (fst[0].isnumeric() or fst[0] == '-' or fst[0] == '+'):
            return 0
        idx = len(fst)
        for i in range(1,len(fst)):
            # print(fst[i])
            if not fst[i].isnumeric():
                idx = i
                break
        # print(idx)
        fst = fst[:idx]
        if fst == '-' or fst == '+':
            return 0
        int_min = -0x7fffffff - 1
        int_max = 0x7fffffff
        raw = int(fst)
        ret = int_max if raw > int_max else raw
        ret = int_min if ret < int_min else ret
        return ret


s = Solution()
fst = '+-1'
print(s.myAtoi(fst))
