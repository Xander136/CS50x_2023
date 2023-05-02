import csv
import requests


def main():
    # Read NYTimes Covid Database
    download = requests.get(
        "https://raw.githubusercontent.com/nytimes/covid-19-data/master/us-states.csv"
    )
    decoded_content = download.content.decode("utf-8")
    file = decoded_content.splitlines()
    reader = csv.DictReader(file)

    # Construct 14 day lists of new cases for each states
    new_cases = calculate(reader)

    # Create a list to store selected states
    states = []
    print("Choose one or more states to view average COVID cases.")
    print("Press enter when done.\n")

    while True:
        state = input("State: ")
        if state in new_cases:
            states.append(state)
        if len(state) == 0:
            break

    print(f"\nSeven-Day Averages")

    # Print out 7-day averages for this week vs last week
    comparative_averages(new_cases, states)


# TODO: Create a dictionary to store 14 most recent days of new cases by state
def calculate(reader):
    # store 14 values in the list
    # for each state
    for state in states:
        new_cases = {}
        new_cases['State'] = state


        # when the length of the list is great they 14
            # removing the first element from the list.
        # by appending each new day’s data to end of the list

    # create a dictionary new_cases
        # Keys in this dict will be the names of states
        # values for each of those keys will be the most recent 14 days of new cases

    # create a second dictionary previous_cases
        #  keeps track of each day’s new cases as it’s calculated.

    # return the new_cases dictionary

# TODO: Calculate and print out seven day average for given state
def comparative_averages(new_cases, states):
    # calculate this week’s 7-day average
    # summing up the last 7 elements in the list for a selected state
    # then dividing this by 7

    # create a 7-day average for the previous week
    # summing up the last 7 elements in the list for a selected state
    # then dividing this by 7

    # calculate the percent increase or decrease,
    # taking the difference of the two 7-day averages
    # and dividing by last week’s average
main()
