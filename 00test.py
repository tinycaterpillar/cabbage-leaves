import random

with open("input.txt", 'w') as f:
    s = 'RINGS'
    l = random.randint(1, 20)
    seq = "".join(random.choices(s, k = l))
    f.write(seq)
    f.write('\n')
    b = random.randint(1, 100)
    f.write("".join(random.choices(s, k = b)))
    f.write('\n')
    f.write("".join(random.choices(s, k = b)))
    f.write('\n')