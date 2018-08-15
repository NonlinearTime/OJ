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

pattern = "abcd"
stri = "cdabcda"
# print(stri.find(pattern))

start = 0
tot = 0
end = len(stri)
times = int(len(stri) / len(pattern)) + 2
pre = pattern * times
print(pattern * times)
print(pre.find(stri))
while True:
    print(stri[start:end])
    ret = stri.find(pattern,start, end)
    if ret == -1:
        break
    tot += 1
    start = ret + len(pattern)
print(tot)
