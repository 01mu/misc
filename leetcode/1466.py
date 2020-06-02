connections = [[0,1],[1,3],[2,3],[4,0],[4,5]]
n = 6

a = {}

class Node:
    def __init__(self, val, t, parent):
        self.to = []

        self.val = val
        self.parent = parent

        if t != None:
            self.to.append(t)

a[0] = Node(0, None, None)

for c in connections:
    if c[0] in a:
        a[c[0]].to.append(c[1])
    else:
        a[c[0]] = Node(c[0], c[1], a[c[1]])

    if c[1] in a:
        if a[c[1]].parent != None:
            a[c[1]].parent = a[c[0]]
    else:
        a[c[1]] = Node(c[1], None, a[c[0]])

for i in range(n):
    print(str(i) + ': ' + str(a[i].to) + ' parent: ', end =" ")

    if a[i].parent != None:
        print(str(a[i].parent.val), end =" ")

    print('')
