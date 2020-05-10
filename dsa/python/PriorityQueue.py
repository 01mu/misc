class PriorityQueue:
    class Node:
        def __init__(self, value):
            self.value = value

    def __init__(self, maxSize):
        self.maxSize = maxSize
        self.current_size = 0
        self.array = [None] * maxSize

    def empty(self):
        return self.current_size == 0

    def insert(self, value):
        if self.current_size == self.maxSize:
            return False

        self.array[self.current_size] = self.Node(value)
        self.trickle_up(self.current_size)

        self.current_size += 1

        return True

    def insert_at(self, index, value):
        new_node = self.Node(value)
        self.array[index] = new_node

    def trickle_up(self, index):
        parent = int((index - 1) / 2)
        bottom = self.array[index]

        while (index > 0 and self.array[parent].value < bottom.value):
            self.array[index] = self.array[parent]
            index = parent
            parent = int((parent - 1) / 2)

        self.array[index] = bottom

    def remove(self):
        self.current_size -= 1

        root = self.array[0]
        self.array[0] = self.array[self.current_size]
        self.trickle_down(0)

        return root

    def trickle_down(self, index):
        larger_child = 0
        top = self.array[index]

        while(index < self.current_size/2):
            left_child = 2 * index + 1
            right_child = left_child + 1

            if(right_child < self.current_size and
                self.array[left_child].value < self.array[right_child].value):
                larger_child = right_child
            else:
                larger_child = left_child

            if(top.value >= self.array[larger_child].value):
                break

            self.array[index] = self.array[larger_child]
            index = larger_child

        self.array[index] = top

    def change(self, index, new_value):
        if(index < 0 or index >= self.current_size):
            return False

        old_value = self.array[index].value
        self.array[index].value = new_value

        if old_value < new_value:
            self.trickle_up(index)
        else:
            self.trickle_down(index)

        return True

    def sort(self):
        old_size = self.current_size

        temp = [None] * self.current_size
        j = 0

        for i in self.array:
            new_node = self.Node(i.value)
            temp[j] = new_node

            j += 1

        self.array = temp

        j = self.current_size / 2 - 1

        while j >= 0:
            self.trickle_down(int(j))
            j -= 1

        j = self.current_size - 1

        while j >= 0:
            self.insert_at(int(j), self.remove().value)
            j -= 1

        self.current_size = old_size
