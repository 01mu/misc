class PriorityQueue:
    class Node:
        def __init__(self, value):
            self.value = value

    def __init__(self, v):
        self.size = 0
        self.array = []

        for i in v:
            self.insert(i)

    def display(self):
        i = 0

        while i < self.size:
            print(self.array[i].value)
            i += 1

    def empty(self):
        return self.size == 0

    def insert(self, value):
        self.array.append(None)
        self.array[self.size] = self.Node(value)
        self.trickle_up(self.size)
        self.size += 1
        return True

    def remove(self):
        self.size -= 1
        root = self.array[0]
        self.array[0] = self.array[self.size]
        self.trickle_down(0)
        return root

    def trickle_up(self, index):
        parent_idx = int((index - 1) / 2)
        parent_val = self.array[parent_idx].value
        bottom = self.array[index]

        while index > 0 and parent_idx >= 0 and parent_val < bottom.value:
            self.array[index] = self.array[parent_idx]
            index = parent_idx
            parent_idx = int((index - 1) / 2)

        self.array[index] = bottom

    def trickle_down(self, index):
        larger_child = 0
        top = self.array[index]

        while index < self.size / 2:
            lc = 2 * index + 1
            rc = lc + 1

            if rc < self.size and self.array[lc].value < self.array[rc].value:
                larger_child = rc
            else:
                larger_child = lc

            if top.value >= self.array[larger_child].value:
                break

            self.array[index] = self.array[larger_child]
            index = larger_child

        self.array[index] = top

    def change(self, index, new_value):
        if index < 0 or index >= self.size:
            return False

        old_value = self.array[index].value
        self.array[index].value = new_value

        if old_value < new_value:
            self.trickle_up(index)
        else:
            self.trickle_down(index)

        return True

    def sort(self):
        j = self.size / 2 - 1
        k = self.size - 1

        while j >= 0:
            self.trickle_down(int(j))
            j -= 1

        while k >= 0:
            self.array[k] = self.Node(self.remove().value)
            k -= 1

        self.size = len(self.array)
