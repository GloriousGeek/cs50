from cs50 import get_float

while True:
    try:
        get_dollars = get_float(input("Change owed: "))
        if user_input > 0:
            break
        else:
            print("Enter a positive value")
    except ValueError:
        print("Enter a valid digit")

def quarters(dollars):
    for i in dollars:
        if dollars >= 0.25:
            i += 1
        return i


