from cs50 import get_float

try:
    user_input = get_float(input("Change owed: "))
except ValueError:
    print("Enter a valid digit")


