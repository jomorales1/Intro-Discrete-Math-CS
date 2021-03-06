def can_be_extended_to_solution(perm):
    i = len(perm) - 1
    for j in range(i):
        if i - j == abs(perm[i] - perm[j]):
            return False
    return True


def generate_permutations(perm, n):
    if len(perm) == n:
        print(perm)
        exit()
    for k in range(n):
        if k not in perm:
            perm.append(k)
            generate_permutations(perm, n)
            perm.pop()


def extend(perm, n):
    if len(perm) == n:
        global solutions
        solutions += 1
        print(perm)
        return
    for k in range(n):
        if k not in perm:
            perm.append(k)
            if can_be_extended_to_solution(perm):
                extend(perm, n)
            perm.pop()


solutions = 0
n = int(input("Enter n: "))
extend(perm = [], n = n)
print("Solutions found: " + str(solutions))
