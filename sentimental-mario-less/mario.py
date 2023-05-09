# create mario less with python

import cs50

while True:
    no_blocks = get_int("Height: ")
    if no_blocks in range(1, 9):
        break

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
