from pyfiglet import Figlet
from sys import argv

## Expects zero or two command-line arguments:
## Zero if the user would like to output text in a random font.
if len(argv) == 0:
    font = random()
elif len(argv) == 2:
    ## Two if the user would like to output text in a specific font
        ## in which case the first of the two should be -f or --font
        ## and the second of the two should be the name of the font.
else:
    print("Usage: Expects zero or two command-line arguments ")
## Prompts the user for a str of text.

## Outputs that text in the desired font.
fonts = Figlet.getFonts()
print(fonts)
# figlet = Figlet()