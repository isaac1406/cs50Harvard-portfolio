from cs50 import get_int

while True:
    n = get_int("Height: ")
    if n > 0 & n < 9:
        break

for i in range(n):
    space = n - (i + 1)
    hashtag = i + 1
    print(" " * space, end="")
    print("#" * hashtag, end="")
    print()
