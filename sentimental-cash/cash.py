from cs50 import get_float

while True:
    n = get_float("Change: ")
    if n > 0:
        break

coins = 0
while n > 0:
    if n >= 0.25:
        n -= 0.25
    elif n >= 0.10:
        n -= 0.10
    elif n >= 0.05:
        n -= 0.05
    else:
        n -= 0.01
    coins += 1

print(coins)
