import numpy as np


class Ligne:

    def __init__(self, onset, offset):
        self.onset = np.array(onset)
        self.offset = np.array(offset)

    def length(self):
        return (np.sum(np.sqrt((self.offset - self.onset) ** 2)))

    def clean(self, wmap):
        if self.length() > 0:
            for d in range(int(self.length())):
                point = self.onset + \
                    ((self.offset - self.onset) / self.length())*d
                wmap[int(point[1])][int(point[0])] = '0'
        else:
            wmap[int(self.onset[1])][int(self.onset[0])] = '0'
        return (wmap)

    def __str__(self):
        return (f"[{self.onset}, {self.offset}]")


def search_vertical(wmap, i, j):
    if (wmap[j][i] == '1'):
        ligne = Ligne((i, j), (0, 0))
        y = j
        while (wmap[y][i] == '1' and y < len(wmap) - 1):
            y += 1
        ligne.offset = np.array((i, y))
        if y - j == 1:
            ligne.offset = np.array((i, j))
        return (ligne)


def search_horizontal(wmap, i, j):
    if (wmap[j][i] == '1'):
        ligne = Ligne((i, j), (0, 0))
        x = i
        while (wmap[j][x] == '1' and x < len(wmap[0]) - 1):
            x += 1
        ligne.offset = np.array((x, j))
        if x - i == 1:
            ligne.offset = np.array((i, j))
        return (ligne)


def search_diagonal(wmap, i, j):
    if (wmap[j][i] == '1'):
        ligne = Ligne((i, j), (0, 0))
        y = j
        x = i
        while (wmap[y][x] == '1' and y < len(wmap) - 1) and x < len(wmap[0]) - 1:
            y += 1
            x += 1
        ligne.offset = np.array((x, y))
        if y - j == 1 and x - i == 1:
            ligne.offset = np.array((i, j))
        return (ligne)


def find_longer(wmap, i, j):
    if (wmap[j][i] == '1'):
        funs = [search_vertical, search_horizontal, search_diagonal]
        results = [f(wmap, i, j) for f in funs]
        lengths = [x.length() for x in results]
        for i in results:
            if i.length() == max(lengths):
                return (i)


def print_map(wmap):
    for i in wmap:
        print("".join(i))


def search_form(wmap, i, j):
    wmap_x_len = len(wmap[0])
    wmap_y_len = len(wmap)
    print(f"len = {wmap_y_len} -- I = {i} -- J = {j}")
    if (j < wmap_y_len and i < wmap_x_len):
        point = find_longer(wmap, i, j)
        if (point):
            print("\n")
            print(point)
            print_map(wmap)
            search_form(point.clean(wmap), i + 1, j)
        else:
            search_form(wmap, i + 1, j)
    elif (i == wmap_x_len and j < wmap_y_len):
        search_form(wmap, 0, j + 1)


if __name__ == "__main__":
    wmap = [list("111111111111111111111111"),
            list("100000000000000000000001"),
            list("100000000000000000000001"),
            list("100000000000000000000001"),
            list("100000111110000101010001"),
            list("100000100010000000000001"),
            list("100000100010000100010001"),
            list("100000100010000000000001"),
            list("100000110110000101010001"),
            list("100000000000000000000001"),
            list("100000000000000000000001"),
            list("100000000000000000000001"),
            list("100000000000000000000001"),
            list("100000000000000000000001"),
            list("100000000000000000000001"),
            list("100000000000000000000001"),
            list("111111111000000000000001"),
            list("110100001000000000000001"),
            list("110000101000000000000001"),
            list("11010000100000000000N001"),
            list("110111111000000000000001"),
            list("110000000000000000000001"),
            list("111111111000000000000001"),
            list("111111111111111111111111"),
            ]
    print(search_form(wmap, 0, 0))
