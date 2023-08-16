# get user input
word = input("camelCase: ")

words = []
letters = ""

for letter in word:
    while not letter.isupper() and letter != "\n":
        letters += letter
    words.append()
    letters = ""

words.join("_")
print(f"snake_case: {words}")