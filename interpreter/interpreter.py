# get user input
expression = input("Expression: ")
expression = expression.split(" ")
x = int(expression[0])
y = expression[1]
z = int(expression[2])


match y:
    case "+":
        print(float(x + y))
    case "-":
        print(float(x - y))
    case "*":
        print(float(x * y))
    case "/":
        print(float(x / y))
    case _:
        print("Try again.")


