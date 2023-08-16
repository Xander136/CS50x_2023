# get user input
word = input("camelCase: ")

letters = ""
words = []

for letter in word:
    if letter.islower():
        letters += letter
    elif letter.isupper():
        words.append(letters)
        letters = ""
        letters += letter

snake_case = words.join("_")

print(f"snake_case: {snake_case}")
