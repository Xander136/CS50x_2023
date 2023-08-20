def main():
    # get plate
    plate = input("Plate: ")
    if is_valid(plate):
        print("Valid")
    else:
        print("Invalid")


"""
1. “All vanity plates must start with at least two letters.”
2. “… vanity plates may contain a maximum of 6 characters (letters or numbers)
    and a minimum of 2 characters.”
3. “Numbers cannot be used in the middle of a plate;
    they must come at the end. For example,
    AAA222 would be an acceptable … vanity plate;
    AAA22A would not be acceptable.
    The first number used cannot be a ‘0’.”
4. “No periods,
    spaces,
    or punctuation marks are allowed.”
"""


def is_valid(s):
    if not start_two_letters(s):
        return False

    if not max_six_min_two(s):
        return False

    if not no_middle_numbers(s):
        return False

    if first_number_zero(s):
        return False

    if not has_invalid_chars(s):
        return False
    # return true if all checks passed
    return True

def start_two_letters(s):
    for char in s[0:2]:
        # check if first 2 characters are alphabet
        if not char.isalpha():
            return False
    return True


def max_six_min_two(s):
    length = len(s)
    if length > 6 or length < 2:
        return False

    return True


def no_middle_numbers(s)
    if s[-1].isalpha() and s.isalnum():
        return False

    return True



main()