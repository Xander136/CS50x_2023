from sys import argv
from pyfiglet import Figlet as figlet

fonts = figlet.getFonts()



## Expects zero or two command-line arguments:
## Zero if the user would like to output text in a random font.
if len(argv) == 0:
    font = random.choice(fonts)
## Two if the user would like to output text in a specific font
elif len(argv) == 2:
    ## in which case the first of the two should be -f or --font
    if (argv[1] != "-f" or argv[1] != "--font"):
        print("2nd argument should be -f or --font")
        exit(1)
    ## and the second of the two should be the name of the font.
    if (argv[2] not in fonts):
        print("2nd argument should be a valiid font")


else:
    print("Usage: Expects zero or two command-line arguments ")
## Prompts the user for a str of text.

## Outputs that text in the desired font.
figlet.setFont(font="slant")
print(figlet.renderText("wow"))
