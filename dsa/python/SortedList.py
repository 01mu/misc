class SortedList:
    class Link:
        def __init__(self, key, data):
            self.key = key
            self.data = data
            self.next = None

        def display(self):
            print('[' + str(self.key) + ':' + str(self.data) + ']', end = ' ')

    def __init__(self):
        self.root = None

    def insert(self, key, data):
        link = SortedList.Link(key, data)

        previous = None
        current = self.root

        while current != None and link.key > current.key:
            previous = current
            current = current.next

        if previous == None:
            self.root = link
        else:
            previous.next = link

        link.next = current

    def remove(self, key):
        previous = None
        current = self.root

        while current != None and key != current.key:
            previous = current
            current = current.next

        if previous == None:
            self.root = self.root.next
        else:
            previous.next = current.next

    def find(self, key):
        current = self.root

        while current != None and current.key <= key:
            if current.key == key:
                return current

            current = current.next

        return None

    def display(self):
        current = self.root

        while current != None:
            current.display()
            current = current.next

        print('\n')
