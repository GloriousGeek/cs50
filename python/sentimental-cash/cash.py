from cs50 import get_float

while True:
    try:
        user_input = get_float(input("Change owed: "))
        if user_input > 0:
            return user_input
    except ValueError:
        print("Enter a valid digit")


