# 0: UL -> BR
# 1: UR -> BL
# 2: ND

grid = [
    [-1, -1, -1, -1, -1],
    [-1, -1, -1, -1, -1],
    [-1, -1, -1, -1, -1],
    [-1, -1, -1, -1, -1],
    [-1, -1, -1, -1, -1]
]


def coordinates(x, y):
    res = []
    for i in range(x - 1, x + 2):
        for j in range(y - 1, y + 2):
            if (i >= 0 and i <= 4) and (j >= 0 and j <= 4) and not (i == x and j == y):
                if grid[i][j] == 0 or grid[i][j] == 1 or grid[i][j] == 2:
                    res.append([i, j])
    
    return res


def check_nd():
    nd = 0
    for l in grid:
        for e in l:
            if e == 2:
                nd += 1
    
    return nd <= 9 


def check(x, y):
    if grid[x][y] == 2:
        return check_nd()
    neighbors = coordinates(x, y)
    for p in neighbors:
        if grid[p[0]][p[1]] == 2:
            continue
        if p[0] == x or p[1] == y:
            if grid[p[0]][p[1]] != grid[x][y]:
                return False
        else:
            if grid[x][y] == 0:
                if (p[0] == x - 1 and p[1] == y + 1) or (p[0] == x + 1 and p[1] == y - 1):
                    continue
            else:
                if (p[0] == x - 1 and p[1] == y - 1) or (p[0] == x + 1 and p[1] == y + 1):
                    continue
            if grid[p[0]][p[1]] == grid[x][y]:
                return False

    return True


def check_all():
    lines = 0
    for i in range(5):
        for j in range(5):
            if grid[i][j] == 0 or grid[i][j] == 1:
                lines += 1
    return lines == 16


def backtrack(x, y):
    if check_all():
        for i in range(5):
            for j in range(5):
                print(str(grid[i][j]), end=" ")
            print()
        print()
        return
    for k in range(3):
        prev = grid[x][y]
        grid[x][y] = k
        if check(x, y):
            if y < 4:
                backtrack(x, y + 1)
            else:
                backtrack(x + 1, 0)
        grid[x][y] = prev


# TODO: Implement the solution using the backtrack technique
backtrack(0, 0)