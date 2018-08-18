class Solution:
    def __int__(self):
        pass

    def smallestRange(self, nums):
        """
        :type nums: List[List[int]]
        :rtype: List[int]
        """
        rec = {}
        res = []
        k = len(nums)
        rlength = 0x7fffffff

        for idx, num_list in enumerate(nums):
            for item in num_list:
               if rec.get(item, None) is None:
                    rec[item] = {idx}
               else:
                    rec[item].add(idx)

        print(rec)

        keys = sorted(rec.keys())
        print(keys)

        for item in keys:
            if rec[item].__len__() == k:
                return [item,item]

        for idx, key in enumerate(keys):
            tmp_set = rec[key]
            local_res = [key]
            for i in range(idx + 1, len(keys)):
                if not keys[i] - key < rlength:
                    break
                tmp_set.update(rec[keys[i]])
                local_res.append(keys[i])
                if tmp_set.__len__() == k:
                    rlength = keys[i] - key
                    res = local_res
        return [res[0], res[-1]]







s = Solution()

nl = [[10,10],[11,11]]
print(s.smallestRange(nl))

