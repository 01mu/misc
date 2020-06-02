class Solution(object):
    def minReorder(self, n, connections):
        class Node:
            def __init__(self, val, t, parent):
                self.to = []

                self.val = val
                self.parent = parent

                if t != None:
                    self.to.append(t)

        a = {}
        count = 0

        a[0] = Node(0, None, None)

        for c in connections:
            if c[0] in a:
                a[c[0]].to.append(c[1])
            else:
                a[c[0]] = Node(c[0], c[1], a[c[1]])

            if c[1] in a:
                a[c[1]].parent = a[c[0]]
            else:
                a[c[1]] = Node(c[1], None, a[c[0]])

        a[0].parent = None

        for i in range(n):
            if a[i].parent != None:
               if a[i].val in a[a[i].parent.val].to:
                   count += 1

        return count

connections = [[0,1],[1,3],[2,3],[4,0],[4,5]]
n = 6

solution = Solution()
print(solution.minReorder(n, connections))
