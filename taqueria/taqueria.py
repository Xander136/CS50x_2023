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
#     prompting them for items
#         one per line,
#         Treat the user’s input case insensitively.
        item = input("Item: ").title()
#         After each inputted item,
#         Ignore any input that isn’t an item
        if item in menu:
#         display the total cost of all items inputted thus far
            total = total + menu[item]
#         prefixed with a dollar sign ($) and formatted to two decimal places
        print(f"Total: ${total:.2f}", end="\n")

# end if ctrl-D is detected
    except EOFError:
        break
print("\n")
