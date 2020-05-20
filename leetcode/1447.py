class Solution(object):
    def gcd(self, x, y):
       while(y):
           x, y = y, x % y
       return x

    def simplifiedFractions(self, n):
        arr = []
        for i in range(n):
            j = 1
            while j < i:
                if self.gcd(j, i) == 1:
                    arr.append(str(j) + '/' + str(i))
                j += 1
        return arr

solution = Solution()
print solution.simplifiedFractions(5)
