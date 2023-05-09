# create mario less with python



while True:
    no_blocks = int("Height: ")
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
        space -= 1

    while block > 0:
        print("#", end="")
        block -= 1

    print("")
    n += 1

    if no_block >= n:
        break
