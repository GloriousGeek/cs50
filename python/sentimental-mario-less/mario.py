def main():
    # Re-prompt the user for value b/w 1 and 8
    while True:
        # Try to Convert the input to an int
        try:
            height = int(input("Height: "))
            if 1 <= height <= 8:
                # Exit the loop
                break
            else:
                print("Enter height between 1 and 8")
        # Except this condition
        except ValueError:
            print("Non Numeric Value")

    # Print the pyramid
    for i in range(1, height + 1):
        # Print spaces
        for j in range(height - i):
            print(" ", end="")
        # Print hash
        for k in range(i):
            print("#", end="")
        # Move to the next line after each row
        print()


# Call main
main()
