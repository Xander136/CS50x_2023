import os

menu = {
    "Baja Taco": 4.00,
    "Burrito": 7.50,
    "Bowl": 8.50,
    "Nachos": 11.00,
    "Quesadilla": 8.50,
    "Super Burrito": 8.50,
    "Super Quesadilla": 9.50,
    "Taco": 3.00,
    "Tortilla Salad": 8.00
}

total = 0

# until the user inputs control-d
while True:
    try:
        item = input("Item: ")
        if item in menu:
            total = total + menu[item]
        print(f"Total: ", end="\n")
    except EOFError:
        return False
#     prompting them for items
#         one per line,

#         After each inputted item,
#         display the total cost of all items inputted thus far
#         prefixed with a dollar sign ($) and formatted to two decimal places
#         Treat the user’s input case insensitively.
#         Ignore any input that isn’t an item

