def main():
    height = int(input("Height: "))
    # Re-prompt the user for value b/w 1 and 8
    while height < 1 or height > 8:
        height


    # Print the pyramid
    for i in range(height):
        # Print spaces
        for j in range(height - i):
            print(" ", end = "")
        # Print hash
        for k in range(i):
            print("#", end= "")
        # Move to the next line after each row
        print()

main()






