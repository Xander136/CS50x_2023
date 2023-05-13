# create readability in python

from cs50 import get_string, get_int

main():
    # get string of text
    text = get_string("Text: ")
    # print("%s\n", text)

    # count letters
    letters = count_letters(text)
    # print number of letters
    print("%i letters", letters)

    # count words
    words = count_words(text) + 1
    # print number of words
    print("%i words", words)

    # count sentences
    sentences = count_sentence(text)
    # print number of sentences
    print("%i sentences", sentences)

    # Compute Coleman-Liau index
    l = (100 * ((float) letters / words))
    s = (100 * ((float) sentences / words))
    index = round(0.0588 * l - 0.296 * s - 15.8)

    if (index < 1)
    {
        print("Before Grade 1")
    }
    else if (index > 15)
    {
        print("Grade 16+")
    }
    else //Grade 1 to 15
    {
        print("Grade %i", (int) index)
    }


count_letters(text):


count_words(text):


count_sentence(text):


 if __name__ == '__main__':
    main()