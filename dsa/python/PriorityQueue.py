class PriorityQueue:
    class Node:
        def __init__(self, value):
            self.value = value

    def __init__(self, maxSize):
        self.maxSize = maxSize
        self.currentSize = 0
        self.array = [None] * maxSize

    def empty(self):
        return self.currentSize == 0

    def insert(self, value):
        if self.currentSize == self.maxSize:
            return False

        self.array[self.currentSize] = self.Node(value)

        return True

pq = PriorityQueue(10)

print(pq.empty())

for i in range(10):
    pq.insert(i)
