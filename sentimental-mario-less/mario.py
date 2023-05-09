# create mario less with python

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

    # print space
    while space > 0:
        print(" ", end="")
        space -= 1

    # print blocks
    while block > 0:
        print("#", end="")
        block -= 1

    # print new line
    print("")
    n += 1

    # loop until all blocks are printed
    if no_blocks < n:
        break
