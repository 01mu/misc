l = "Keep calm and code on".split()
l[0] = l[0][0].lower() + l[0][1:]
l = sorted(l, key=len)
s = ""

for i in range(len(l)):
    s += l[i] + " "

print (s[0].upper() + s[1:])[0:-1]
