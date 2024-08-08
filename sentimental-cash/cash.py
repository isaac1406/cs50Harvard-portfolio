from cs50 import get_float

while True:
    n = get_float("Change: ")
    if n > 0:
        break

cents = round(n * 100)

coins = 0
while cents > 0:
    if cents >= 25:
        cents -= 25
        coins += 1
    elif cents >= 10:
        cents -= 10
        coins += 1
    elif cents >= 5:
        cents -= 5
        coins += 1
    else:
        cents -= 1
        coins += 1

print(coins)
