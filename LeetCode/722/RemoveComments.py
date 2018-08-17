class Solution:
    def removeComments(self, source):
        """
        :type source: List[str]
        :rtype: List[str]
        """
        concat = '|'.join(source) + '|'
        res = ''
        single_cmt = False
        multi_cmt = False
        i = 0
        while i < len(concat) - 1:
            if single_cmt:
                if concat[i] == '|':
                    single_cmt = False
                else:
                    i += 1
            elif multi_cmt:
                if concat[i] == '*' and concat[i+1] == '/':
                    multi_cmt = False
                    i += 2
                else:
                    i += 1
            else:
                if concat[i] == '/' and concat[i+1] == '*':
                    multi_cmt = True
                    i += 2
                elif concat[i] == '/' and concat[i+1] == '/':
                    single_cmt = True
                    i += 2
                else:
                    res += concat[i]
                    i += 1
        rmved = list(filter(lambda x: x != '', res.split("|")))
        return rmved


l = ["a//*b//*c","bl/*/ank","d//*e*//f"]

s = Solution()
print(s.removeComments(l))