from cs50 import get_float

def main():



def get_dollars():
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
    # Initializing a variable to count quarters
    q = 0
    while dollars >= 25:
        q += 1
        dollars -= 0.25
    return q


def dimes(dollars):
    d = 0
    while dollars >= 10:
        d += 1
    return d


def nickels(dollars):
    n = 0
    while dollars >= 5:
        n += 1
    return n


def pennies(dollars):
    p = 0
    while dollars >= 1:
        p += 1
    return p


main()
