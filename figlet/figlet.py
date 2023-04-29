from pyfiglet import Figlet\
import os

## Expects zero or two command-line arguments:

    ## Zero if the user would like to output text in a random font.
    ## Two if the user would like to output text in a specific font
        ## in which case the first of the two should be -f or --font
        ## and the second of the two should be the name of the font.
## Prompts the user for a str of text.

## Outputs that text in the desired font.
fonts = Figlet.getFonts()
print(fonts)
# figlet = Figlet()