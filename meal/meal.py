def main():
    # get user input
    time = input("What time is it? ")
    time = convert(time)


    if 7.0 <= time <= 8.0:
        print("breakfast time")
    elif 12.0 <= time <= 13.0:
        print("lunch time")
    elif 18.0 <= time <= 19.0:
        print("dinner time")
    else:
        print("Try again.")



def convert(time):
    hours = float(time.split(":")[0])
    minutes = int(time.split(":")[1])
    minutes = float((minutes/6.0) * 0.1)
    return (hours + minutes)

if __name__ == "__main__":
    main()