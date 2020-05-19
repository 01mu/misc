s = [9,8,7,6,5,4,3,2,1]
e = [10,10,10,10,10,10,10,10,10]
q = 5
c = 0

for i in range(len(s)):
    if e[i] - s[i] >= q:
        c += 1

print c
