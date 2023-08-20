# get user input
words = input("Input: ")


vowels = ["a", "e", "i", "o", "u", "A", "E", "I", "O", "U"]

for vowel in vowels:
    # remove lower case
    words = words.replace(vowel, "")

print(words)