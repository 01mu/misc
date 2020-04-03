class HashMap:
    class Item:
        def __init__(self, data):
            self.data = data

    def __init__(self, size):
        self.size = size
        self.array = [None] * size
        self.delete = self.Item(-1)

    def hash_func(self, key):
        return key & self.size

    def hash_func_step(self, key):
        return 5 - key & self.size

    def insert(self, item):
        key = item.data
        hash_val = self.hash_func(key)
        step_size = self.hash_func_step(key)

        while self.array[hash_val] != None and self.array[hash_val].data != -1:
            #hash_val += 1
            hash_val += step_size

            hash_val %= self.size

        print(hash_val),

        self.array[hash_val] = item

    def remove(self, key):
        hash_val = self.hash_func(key)
        step_size = self.hash_func_step(key)

        while self.array[hash_val] != None:
            if self.array[hash_val].data == key:
                temp = self.array[hash_val]
                self.array[hash_val] = self.delete

                return temp

            #hash_val += 1
            hash_val += step_size

            hash_val %= self.size

        return None

    def find(self, key):
        hash_val = self.hash_func(key)
        step_size = self.hash_func_step(key)

        while self.array[hash_val] != None:
            if self.array[hash_val].data == key:
                return self.array[hash_val]

            #hash_val +=1
            hash_val += step_size

            hash_val %= self.size

        return None

    def display(self):
        j = 0

        while j < self.size:
            if self.array[j] != None:
                print(self.array[j].data),
            else:
                print('*'),

            j += 1


hm = HashMap(7)

for i in range(3):
    hm.insert(HashMap.Item(i))

