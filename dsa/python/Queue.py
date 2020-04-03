class Queue:
    def __init__(self):
        self.vals = []

    def add(self, val):
        self.vals.append(val)

    def pop(self):
        if len(self.vals) == 0:
            return None

        i = 0

        ret = self.vals[0]
        new = []

        while i < len(self.vals)-1:
            new.append(self.vals[i+1])

            i += 1

        self.vals = new

        return ret

    def display(self):
        for v in self.vals:
            print(v),

    def length(self):
        return len(self.vals)
