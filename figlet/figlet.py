from sys import argv
from sys import exit
from pyfiglet import Figlet
import random

figlet = Figlet()

fonts = figlet.getFonts()



## Expects zero or two command-line arguments:
## Zero if the user would like to output text in a random font.
if len(argv) == 1:
    font = random.choice(fonts)

## Two if the user would like to output text in a specific font
elif len(argv) == 3:
    ## in which case the first of the two should be -f or --font
    if not (argv[1] == '-f' or argv[1] == '--font'):
        print("Invalid usage of font")
        exit(1)

    ## and the second of the two should be the name of the font.
    ## check if font is valid
    if not (argv[2] in fonts):
        print("2nd argument should be a valid font")
        exit(1)

    ## set font user chose
    font = argv[2]

## if not zero or two command-line arguments
else:
    print("Invalid usage of arg")
    exit(1)

## Prompts the user for a str of text.
word = input("Words: ")
## Outputs that text in the desired font.
figlet.setFont(font=font)
print(figlet.renderText(word))
