def number_of_digits(n):
    res = 0
    if n == 0:
        return 0
    
    while abs(n) > 0:
        n = n // 10
        res += 1
    return res


def number_of_digits_recursive(n):
    if abs(n) == 0:
        return 0
    return 1 + number_of_digits_recursive(n // 10)
    

def search_number():
    for n in range(7, 100, 7):
        print(n, end = " ")
        if n % 10 == n // 7:
            print("\nNumber found: " + str(n))
    print()


def search_long_number():
    n = 57
    while(True):
        digits = number_of_digits(n)
        if n % 10 ** (digits - 1) == n // 57:
            print("\nNumber found: " + str(n))
            break
        print(n, end = " ")
        n = n + 57
    print()

search_number()
print()
search_long_number()
print(number_of_digits_recursive(145))