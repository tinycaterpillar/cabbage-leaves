import random

n = random.randint(3, 30)
m = random.randint(0, n*(n-1)//2)
with open("input.txt", 'w') as f:
    f.write(f"{n} {m}\n")