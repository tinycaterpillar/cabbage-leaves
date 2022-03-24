class Joeun_jiksagakyeong():
    def __init__(self, a, b, c, d):
        self.x = a
        self.y = b
        self.w = c
        self.h = d

def loU(l, r):
    if l.x >= r.x: l, r = r, l
    if l.y >= r.y: l.y, r.y = l.y - l.h, 2*l.y - r.y - r.h

    if l.x + l.w <= r.x or l.y + l.h <= r.y: return 0
    else:
        if l.y + l.h <= r.y + r.h:
            intersect_area = (l.x + l.w - r.x)*(l.y + l.h - r.y)
            union_area = l.w * l.h + r.w * r.h - intersect_area
        else:
            intersect_area = (l.x + l.w - r.x)*(r.y + r.h - r.w)
            union_area = l.w * l.h + r.w * r.h - intersect_area
        return intersect_area / union_area

my_list = [[0, 0, 2, 2], [1, 1, 3, 2], [0, 1, 2, 3]]
Joeun_list = [Joeun_jiksagakyeong(*i) for i in my_list]
maxval = -1
for i in range(len(my_list)):
    for j in range(i+1, len(my_list)):
        maxval = max(maxval, loU(Joeun_list[i], Joeun_list[j]))

print(maxval)