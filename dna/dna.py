import csv
import sys


def main():

    # TODO: Check for command-line usage
    if len(sys.argv) != 3:
        print("Usage: python dna.py data.csv sequence.txt")
        sys.exit(1)

    # TODO: Read database file into a variable
    with open(sys.argv[1], 'r') as file:
        reader = csv.DictReader(file)
        data = list(reader)
        # print(data)

    # TODO: Read DNA sequence file into a variable
    with open(sys.argv[2], 'r') as file:
        dna = file.read()
        # print(dna)

    # TODO: Find longest match of each STR in DNA sequence
    # str patterns list
    str = list(data[0].keys())
    str.pop(0)

    # dictiory for file sequences
    sequence_dict = {}

    # loop over patterns
    for pattern in str:
        sequence_dict[pattern] = longest_match(dna, pattern)

    # TODO: Check database for matching profiles
    # number of str patterns needed for a match
    str_to_match = len(str)

    # change to True if match is found
    match_found = False

    # Loop over people in data dictionary
    for person in range(len(data)):
        # number of matched str for the current person
        matched_str = 0
        # Loop over str patterns from csv file header
        for pattern in str:
            # if an str matches
            if int(data[person][pattern]) == sequence_dict[pattern]:
                # increment matched str count
                matched_str += 1

        # if needed matches are satisfied
        if matched_str == str_to_match:
            # print persons name
            print(data[person]["name"])
            match_found = True
            break

    # if no matches found
    if not match_found:
        print("No match")


def longest_match(sequence, subsequence):
    """Returns length of longest run of subsequence in sequence."""

    # Initialize variables
    longest_run = 0
    subsequence_length = len(subsequence)
    sequence_length = len(sequence)

    # Check each character in sequence for most consecutive runs of subsequence
    for i in range(sequence_length):

        # Initialize count of consecutive runs
        count = 0

        # Check for a subsequence match in a "substring" (a subset of characters) within sequence
        # If a match, move substring to next potential match in sequence
        # Continue moving substring and checking for matches until out of consecutive matches
        while True:

            # Adjust substring start and end
            start = i + count * subsequence_length
            end = start + subsequence_length

            # If there is a match in the substring
            if sequence[start:end] == subsequence:
                count += 1

            # If there is no match in the substring
            else:
                break

        # Update most consecutive matches found
        longest_run = max(longest_run, count)

    # After checking for runs at each character in seqeuence, return longest run found
    return longest_run


main()
