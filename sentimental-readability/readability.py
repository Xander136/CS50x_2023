# create readability in python

from cs50 import get_string, get_int

def main():
    # get string of text
    text = get_string("Text: ")

    # count letters
    letters = count_letters(text)
    # print number of letters
    print(f"{letters} letters")

    # count words
    words = count_words(text) + 1
    # print number of words
    print(f"{words} words")

    # count sentences
    sentences = count_sentence(text)
    # print number of sentences
    print(f"{sentences} sentences")

    # Compute Coleman-Liau index
    l = 100 * (float(letters / words))
    s = 100 * (float(sentences / words))
    index = round(0.0588 * l - 0.296 * s - 15.8)

    if (index < 1):
        print("Before Grade 1")

    elif (index > 15):
        print("Grade 16+")

    else: # Grade 1 to 15
        print(f"Grade {int(index)}")

# Function for counting letters from user input
def count_letters(text):
    letters = 0
    # Loop over the string
    for char in text:
        if char.isalpha():
            letters += 1

    return letters


# Function for counting words from user input
def count_words(text):
    words = 0
    # Loop over the string
    for char in text:
        if char == ' ':
            words += 1

    return words


# Function for counting sentences from user input
def count_sentence(text):
    sentences = 0
    # Loop over the string
    for char in text:
        if (char == '!' or char == '.' or char == '?'):
            sentences += 1

    return sentences


if __name__ == '__main__':
    main()
