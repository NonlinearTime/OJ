class Solution:
    def customSortString(self, S, T):
        """
        :type S: str
        :type T: str
        :rtype: str
        """
        dict = {}
        is_in_dict = {}
        rec = {}

        for i in range(26):
            is_in_dict[chr(ord('a') + i)] = False

        for i in range(len(S)):
            dict[S[i]] = i
            rec[i] = []
            is_in_dict[S[i]] = True

        remain = ''

        for i in range(len(T)):
            if not is_in_dict[T[i]]:
                remain += T[i]
            else:
                rec[dict[T[i]]].append(i)

        str_in_dict = ''

        for v in rec.values():
            for item in v:
                str_in_dict += T[item]

        return str_in_dict + remain


s = Solution()
print(s.customSortString('cba', 'hiouhascnudoiasdb'))