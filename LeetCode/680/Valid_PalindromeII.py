class Solution:
    def validPalindrome(self, s):
        """
        :type s: str
        :rtype: bool
        """
        if len(s) == 0 or len(s) == 1 or len(s) == 2:
            return True
        i = 0
        j = len(s) - 1
        cost = 1
        while i < j:
            if s[i] != s[j]:
                if cost == 0:
                    return False
                if s[i+1] == s[j] and cost == 1:
                    if i+1 == j or i+1 == j-1:
                        i += 1
                        cost -= 1
                    elif s[i+2] == s[j-1]:
                        i += 1
                        cost -= 1
                elif s[j-1] == s[i] and cost == 1:
                    if i == j-1 or i+1 == j-1:
                        j -= 1
                        cost -= 1
                    elif s[j-2] == s[i+1]:
                        j -= 1
                        cost -= 1
                    else: return False
                else:
                    return False
            i+=1
            j-=1
        return True
