from cs50 import get_float


def main():
    # Prompt user for dollars owed
    # Convert dollars to cents
    dollars = 100 * get_dollars()

    # Calculate the number of quarters to give
    quarter_count = quarters(dollars)
    # Update the dollars after subtracting the ones used in quarters
    dollars = dollars - (quarter_count * 25)

    dime_count = dimes(dollars)
    # Update dollars
    dollars = dollars - (dime_count * 10)

    # Calculate number of nickels
    nickel_count = nickels(dollars)
    # Update dollars
    dollars = dollars - (nickel_count * 5)

    # Calculate pennies
    penny_count = pennies(dollars)
    # Update dollars
    dollars = dollars - (penny_count * 1)

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
    while dollars >= 25:
        q += 1
        dollars -= 25
    return q


def dimes(dollars):
    d = 0
    while dollars >= 10:
        d += 1
        dollars -= 10
    return d


def nickels(dollars):
    n = 0
    while dollars >= 5:
        n += 1
        dollars -= 5
    return n


def pennies(dollars):
    p = 0
    while dollars >= 1:
        p += 1
        dollars -= 1
    return p


# Calling main
main()
