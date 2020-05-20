class Solution(object):
    def maxPower(self, s):
        c = 1
        vals = []
        for i in range(len(s)):
            if i > 0 and s[i] == s[i-1]:
                c += 1
            else:
                vals.append(c)
                c = 1
        return max(vals)


s = "hooraaaaaaaaaaay"

solution = Solution()
print solution.maxPower(s)
