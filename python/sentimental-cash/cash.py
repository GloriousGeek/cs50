from cs50 import get_float

while True:
    try:
        user_input = get_float(input("Change owed: "))
        if user_input > 0:
            break
        else:
            print("Enter a positive value")
    except ValueError:
        print("Enter a valid digit")

def quarters():
    


