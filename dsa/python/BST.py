class BST:
    class Node:
        def __init__(self, data):
            self.data = data
            self.left = None
            self.right = None

    def __init__(self, data):
        self.root = self.Node(data)

    def find(self, key):
        current = self.root

        while current.data != key:
            if key < current.data:
                current = current.left
            else:
                current = current.right

            if current == None:
                return None

        return current

    def insert(self, key):
        node = self.Node(key)

        if self.root == None:
            self.root = node
            return

        current = self.root

        while True:
            parent = current

            if key < current.data:
                current = current.left

                if current == None:
                    parent.left = node
                    return
            else:
                current = current.right

                if current == None:
                    parent.right = node
                    return

    def inorder(self):
        self.do_inorder(self.root)

    def do_inorder(self, node):
        if node != None:
            self.do_inorder(node.left)
            print(node.data, end = ' ')
            self.do_inorder(node.right)

bst = BST(2)
bst.insert(1)
bst.inorder()
