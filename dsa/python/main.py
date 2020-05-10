from PriorityQueue import PriorityQueue

pq = PriorityQueue(10)
j = 0

for i in [70, 40, 50, 20, 60, 100, 80, 30, 10, 90]:
    pq.insert(i)

pq.sort()

for v in pq.array:
    print(v.value)
