# TODO
from cs50 import get_float
while True:
    d = get_float("Change owed: ")
    if d > 0:
        break
    else:
        continue

cents = round(d * 100)
coin = 0
while cents > 0:
    if cents >= 25:
        cents -= 25

    elif cents >= 10:
        cents -= 10

    elif cents >= 5:
        cents -= 5

    else:
        cents -= 1

    coin += 1

print(coin)

