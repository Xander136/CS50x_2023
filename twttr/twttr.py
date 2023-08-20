# get user input
words = input("Input: ")


# vowels = ["a", "e", "i", "o", "u", "A", "E", "I", "O", "U"]
vowels = ["a", "e", "i", "o", "u"]

for vowel in vowels:
    # remove lower case vowels
    words = words.replace(vowel, "")
    # remove upper case vowels
    words = words.replace(vowel.upper(), "")

print(words)