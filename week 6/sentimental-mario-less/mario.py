# TODO
from cs50 import get_int

while True:
    h = get_int("Height: ")

    if h >= 1 and h <= 8:
        break
    else:
        continue

for i in range(h):
    print(" " * (h - (i + 1)) + "#" * (i + 1))