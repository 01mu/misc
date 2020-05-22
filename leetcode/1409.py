class Solution(object):
    def processQueries(self, queries, m):
        v = []
        c = []
        i = 1
        while i <= m:
            v.append(i)
            i += 1
        for i in range(len(queries)):
            idx = 0
            for j in range(len(v)):
                if queries[i] == v[j]:
                    v.remove(v[j])
                    a = v
                    v = [queries[i]]
                    v.extend(a)
                    c.append(idx)
                idx += 1
        return c

queries = [3, 1, 2, 1]
m = 5

solution = Solution()
print solution.processQueries(queries, m)
