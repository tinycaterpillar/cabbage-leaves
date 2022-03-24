def one(n):
    return [i for i in range(1, 1001) if i%n == 0]

def gcd(a, b): return a if b == 0 else gcd(b, a%b)

def two(a, b):
    return sum(one(1)) - sum(one(a)) - sum(one(b)) + sum(one(gcd(a, b)))

def tree(a):
    ret = [a]

    i = 3
    if a%2 == 0:
        ret.append(2)
        ret.append(a//2)
    while i*i < a:
        if a%i == 0:
            ret.append(i)
            ret.append(a//i)
        i += 2
    if i*i == a: ret.append(i)

    if len(ret) == 1:
        print(f"{a} is a prime number.")
    return ret

def four(a, b):
    return sum([i for i in range(1, 1001) if gcd(i, a) == 1 and gcd(i, b) == 1])