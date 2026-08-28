from fractions import Fraction

def Moore(delta):
    k = delta // 2

    if delta % 2 == 1:
        # delta = 2k + 1
        no = delta * (delta - 1) ** k - 2
        deno = delta * (delta - 1) ** (k - 1) * (delta**2 - delta - 1) - 2

    else:
        # delta = 2k
        no = (delta - 1) ** k - 1
        deno = (delta - 1) ** (k - 1) * (delta**2 - delta - 1) - 1

    return Fraction(no, deno)


def Bipartite(delta):
    no = 2 * (delta + 1)

    if delta % 2 == 1:
        deno = delta**2 + 5 * delta + 2
    else:
        deno = delta**2 + 6 * delta + 2

    return Fraction(no, deno)

def Complete(delta):
    return Fraction(4, 3*delta+4)

for delta in range(3, 10):
    print(f"case delta = {delta}")
    M, B, C = Moore(delta), Bipartite(delta), Complete(delta)
    if M > C:
        print("Moore")
    elif M < C:
        print("Complete")
    else:
        print("same")
    print(M, C)
    print()