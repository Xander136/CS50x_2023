# create mario less with python

import cs50

while True:
    no_blocks = get_int("Height: ")
    if no_blocks in range(1, 10):
        break

block = 0
space = 0
n = 1

while True:
    space = no_block - n
    block = no_block - space

    while space > 0:
        print(" ", end="")
        space