# create mario less with python

from cs50 import get_int

while True:
    try:
        no_blocks = int(input("Height: "))
        if no_blocks in range(1, 9):
            break
    except ValueError:
        print("The input was not a valid integer.")

block = 0
space = 0
n = 1

while True:
    space = no_blocks - n
    block = no_blocks - space

    while space > 0:
        print(" ", end="")
        space -= 1

    while block > 0:
        print("#", end="")
        block -= 1

    print("")
    n += 1

    if no_blocks < n:
        break
