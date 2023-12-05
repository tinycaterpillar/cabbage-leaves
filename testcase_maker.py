import random

n = random.randint(1, 50)
l = "-X"
with open("input.txt", 'w') as f:
    f.write(f"{n}\n")
    for _ in range(n):
        f.write("".join(l[random.randint(0, 1)] for _ in range(n)))
        f.write("\n")
