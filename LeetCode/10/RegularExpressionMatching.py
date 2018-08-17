import re


class Solution:
    def __int__(self):
        pass


    def isMatch(self, s, p):
        """
        :type s: str
        :type p: str
        :rtype: bool
        """
        if s == p:
            return True
        if s == '':
            if p.__len__() != 2 or p == '**':
                return False
            elif p[0] != '*' and p[1] == '*':
                return True
        if s.__len__() == 1 and p == '.':
            return True
        if len(s) >= 2 and len(p) == 1:
            return False

        i, j = 0, 0
        s_ori = s
        s, p = s + '#', p + '#'

        patterns = []

        while i < len(p) - 1:
            if p[i + 1] != '*':
                patterns.append(p[i])
            else:
                patterns.append(p[i] + '*')
                i += 1
            i += 1

        if p[len(p) - 1] != '*':
            patterns.append(p[len(p) - 1])

        rec = [[] for _ in range(patterns.__len__() + 1)]
        rec[0] = [0]

        i = 0

        while True:
            if s[i] == '#' or patterns[j] == '#':
                break
            if s[i] == patterns[j] or patterns[j] == '.':
                rec[j + 1].append(i+1)
                i += 1
                j += 1
            elif len(patterns[j]) == 2 and patterns[j][1] == '*':
                if rec[j + 1].__len__() == 0:
                    rec[j + 1] = rec[j].copy()
                if patterns[j][0] in [s[i], '.']:
                    rec[j + 1].append(i+1)
                    i += 1
                else:
                    j += 1
            else:
                return False
        print(s[i],patterns[j])
        if s[i] != '#':
            return False
        elif patterns[j] == '#':
            return True
        idx = -1
        for i in range(1, rec.__len__() - 1):
            if rec[i].__len__() == 0:
                idx = i
                break
        if idx == -1:
            return True
        print(rec[len(rec) - 2])
        print(rec)
        print(patterns)
        print(i,j,idx)
        remain = ''.join(list(filter(lambda x: len(x) == 1 and x != '#', patterns[idx - 1:])))
        if remain == '':
            return True
        start_idx = s_ori.__len__() - remain.__len__()
        if not start_idx in rec[idx - 1]:
            return False
        else:
            s_new = s_ori[start_idx:]
            print(s_new)
            print(self.isMatch(s_new,remain))
            return self.isMatch(s_new,remain)


class Solution_ref:
    def isMatch(self, s, p):
        m, n = len(s), len(p)
        if n > 0 and p[0] == '*': return False

        s, p = s + '#', p + '#'
        prev = [False] * (m + 1)
        current = [False] * (m + 1)
        prev[-1] = True

        for i in range(n - 1, -1, -1):
            if True not in prev: return False
            if p[i] == '*':
                continue
            elif p[i] != '.' and p[i + 1] == '*':
                current[-1] = prev[-1]
                for j in range(m - 1, -1, -1):
                    current[j] = prev[j] or (p[i] == s[j] and current[j + 1])

            elif p[i] == '.' and p[i + 1] == '*':
                current[-1] = prev[-1]
                for j in range(m - 1, -1, -1):
                    current[j] = current[j + 1] or prev[j]
            elif p[i] == '.':
                for j in range(m - 1, -1, -1):
                    current[j] = prev[j + 1]
            else:
                for j in range(m - 1, -1, -1):
                    current[j] = prev[j + 1] and p[i] == s[j]

            prev = current
            current = [False] * (m + 1)

        return prev[0]

s = Solution()
print(s.isMatch('aasdfasdfasdfasdfas', 'aasdf.*asdf.*asdf.*asdf.*s'))
