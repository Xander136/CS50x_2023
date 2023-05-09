# create mario more with python

# get value of 1 - 8; reject any other input

while True:
    try:
        no_blocks = int(input("Height: "))
        if no_blocks in range(1, 9):
            break
    except ValueError:
        print("The input was not a valid integer.")

# set variables
block = 0
space = 0
n = 1

while True:
    # get number of blocks and spaces to print
    space = no_blocks - n
    block = no_blocks - space
    left_block, right_block = block, block

    # print space
    while space > 0:
        print(" ", end="")
        space -= 1

    # print blocks
    while left_block > 0:
        print("#", end="")
        left_block -= 1

    print("  ", end="")

    # print blocks
    while right_block > 0:
        print("#", end="")
        right_block -= 1

    # print new line
    print("")
    n += 1

    # loop until all blocks are printed
    if right_block < n:
        break
