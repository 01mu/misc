from Queue import Queue

class BinaryTree:
    class Node:
        def __init__(self, val, parent):
            self.val = val
            self.parent = parent
            self.left = None
            self.right = None

    def __init__(self, depth):
        self.root = self.Node(-1, None)
        self.fill(self.root, 0, depth)

    def fill(self, node, v, depth):
        if v == depth:
            return

        node.left = self.Node(v+100, node)
        node.right = self.Node(v-100, node)

        v += 1

        self.fill(node.left, v, depth)
        self.fill(node.right, v, depth)

    def dfs(self):
        self.do_dfs(self.root)

    def bfs(self):
        queue = Queue()

        queue.add(self.root)

        while(queue.length() > 0):
            p = queue.pop()

            print(p.val),

            if p.left != None:
                queue.add(p.left)

            if p.right != None:
                queue.add(p.right)

    def inorder(self):
        self.do_inorder(self.root)

    def postorder(self):
        self.do_postorder(self.root)

    def do_dfs(self, node):
        print(node.val),

        if node.left != None:
            self.do_dfs(node.left)

        if node.right != None:
            self.do_dfs(node.right)

    def do_inorder(self, node):
        if node != None:
            self.do_inorder(node.left)
            print(node.val),
            self.do_inorder(node.right)

    def do_postorder(self, node):
        if node != None:
            self.do_postorder(node.right)
            print(node.val),
            self.do_postorder(node.left)
