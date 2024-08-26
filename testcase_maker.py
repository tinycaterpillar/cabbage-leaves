import random

n = 10
with open("input.txt", 'w') as f:
    f.write(f"{n}\n")
    f.write(' '.join(str(random.randint(1, 10)) for _ in range(n)))
    f.write("\n")
    f.write(' '.join(str(random.randint(1, 10)) for _ in range(n)))
    f.write("\n")

