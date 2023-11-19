from cs50 import get_float

def main():
    # Prompt user for dollars owed
    dollars = get_dollars()

    # Calculate the number of quarters to give
    quarters = quarters(dollars)
    # Update the dollars after subtracting the ones used in quarters
    dollars = dollars - (quarters * 0.25)

    dimes = dimes(dollars)
    # Update dollars
    dollars = dollars - (dimes * 0.10)

    # Calculate number of nickels
    nikels = nickels(dollars)
    # Update dollars
    dollars = dollars - (nickels * 0.5)

    # Calculate pennies
    pennies = pennies(dollars)
    # Update dollars
    dollars = dollars - (pennies * 0.10)


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
