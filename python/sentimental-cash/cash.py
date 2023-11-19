from cs50 import get_float

def main():
    # Prompt user for dollars owed
    dollars = get_dollars()

    # Calculate the number of quarters to give
    quarter_count = quarters(dollars)
    # Update the dollars after subtracting the ones used in quarters
    dollars = dollars - (quarters * 0.25)

    dime_count = dimes(dollars)
    # Update dollars
    dollars = dollars - (dimes * 0.10)

    # Calculate number of nickels
    nickel_count = nickels(dollars)
    # Update dollars
    dollars = dollars - (nickels * 0.5)

    # Calculate pennies
    penny_count = pennies(dollars)
    # Update dollars
    dollars = dollars - (pennies * 0.10)

    # Count the number of coins
    coins = quarter_count + dime_count + nickel_count + penny_count

    print(coins)


def get_dollars():
    while True:
        try:
            user_input = get_float("Change owed: ")
            if user_input > 0:
                return user_input
            else:
                print("Enter a positive value")
        except ValueError:
            print("Enter a valid digit")

def quarters(dollars):
    # Initializing a variable to count quarters
    q = 0
    while dollars >= 0.25:
        q += 1
        dollars -= 0.25
    return q


def dimes(dollars):
    d = 0
    while dollars >= 0.10:
        d += 1
        dollars -= 0.10
    return d


def nickels(dollars):
    n = 0
    while dollars >= 0.5:
        n += 1
        dollars -= 0.5
    return n


def pennies(dollars):
    p = 0
    while dollars >= 0.1:
        p += 1
        dollars -= 0.1
    return p


main()
