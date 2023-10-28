import random

l = [False, False, True] + [True, False]*50
for i in range(3, 100, 2):
    if l[i]:
        for j in range(i*i, 100, i):
            l[j] = False

p = []
for i in range(100):
    if l[i]: p.append(i)

n = random.randint(1, 10)
m = random.randint(1, 1e12)
tar = random.sample(p, n)
with open("input.txt", 'w') as f:
    f.write(f'{n} {m}\n')
    f.write(" ".join(map(str, tar)))
    f.write('\n')