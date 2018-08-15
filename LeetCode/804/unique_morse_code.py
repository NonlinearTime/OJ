# coding=utf-8
class Solution:
    def __int__(self):
        pass

    def uniqueMorseRepresentations(self, words):
        """
        :type words: List[str]
        :rtype: int
        """
        morse = [self.word2morse(word) for word in words]
        # morse = map(self.word2morse, words)
        return self.find_unique_morse(morse)

    def word2morse(self, word):
        morse_table = [".-", "-...", "-.-.", "-..", ".", "..-.", "--.", "....", "..", ".---", "-.-", ".-..", "--", "-.",
                       "---", ".--.", "--.-", ".-.", "...", "-", "..-", "...-", ".--", "-..-", "-.--", "--.."]

        def index(c):
            return ord(c) - ord('a')

        morse_list = [morse_table[index(c)] for c in word]
        res = ''
        for item in morse_list:
            res += item
        return res

    def find_unique_morse(self, morses):
        morse_dic = {}
        tot = 0
        for morse in morses:
            if morse_dic.get(morse) is None:
                morse_dic[morse] = 1
            else:
                morse_dic[morse] +=1
        return len(morse_dic)
s = Solution()
print(s.uniqueMorseRepresentations(['gin', 'zen', 'gig', 'msg']))
