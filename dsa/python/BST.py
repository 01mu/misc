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

            if key == current.data:
                return
            elif key < current.data:
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
        vals = []
        self.do_inorder(self.root, vals)
        return vals

    def do_inorder(self, node, vals):
        if node != None:
            self.do_inorder(node.left, vals)
            vals.append(node.data)
            self.do_inorder(node.right, vals)

    def postorder(self):
        vals = []
        self.do_postorder(self.root, vals)
        return vals

    def do_postorder(self, node, vals):
        if node != None:
            self.do_postorder(node.right, vals)
            vals.append(node.data)
            self.do_postorder(node.left, vals)

    def min(self):
        current = self.root
        last = None

        while current != None:
            last = current
            current = current.left

        return last

    def max(self):
        current = self.root
        last = None

        while current != None:
            last = current
            current = current.right

        return last

    def get_successor(self, node):
        parent = node
        successor = node
        current = node.right

        while current != None:
            parent = successor
            successor = current
            current = current.left

        if successor != node.right:
            parent.left = successor.right
            successor.right = node.right

        return successor

    def delete(self, key):
        current = self.root
        parent = self.root
        del_left = True

        while current.data != key:
            parent = current

            if key < current.data:
                del_left = True
                current = current.left
            else:
                del_left = False
                current = current.right

            if current == None:
                return False

        if current.left == None and current.right == None:
            if current == self.root:
                self.root = None
            elif del_left == True:
                parent.left = None
            else:
                parent.right = None
        elif current.right == None:
            if current == self.root:
                self.root = current.left
            elif del_left == True:
                parent.left = current.left
            else:
                parent.right = current.left
        elif current.left == None:
            if current == self.root:
                self.root = current.right
            elif del_left == True:
                parent.left = current.right
            else:
                parent.right = current.right
        else:
            successor = self.get_successor(current)

            if current == self.root:
                self.root = successor
            elif del_left == True:
                parent.left = successor
            else:
                parent.right = successor

            successor.left = current.left

        return True
