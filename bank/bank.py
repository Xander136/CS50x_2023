

# prompts the user for a greeting
greeting = input("Greeting: ")
greeting = greeting.lower()
greeting = greeting.strip()

# If the greeting starts with “hello”,
if greeting.startswith("hello"):
    print("$0")

# If the greeting starts with an “h” (but not “hello”),
elif greeting.startswith("h"):
    print("$20")

# Otherwise,
else:
    print("$100")

# str.strip([chars]) str.strip([chars])
# str.startswith(prefix[, start[, end]]) Return True if string starts with the prefix, otherwise return False