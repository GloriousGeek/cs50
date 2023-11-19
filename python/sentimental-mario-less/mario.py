height = get_height()

def main():
    for i in range(height):
    for j in range(height):
        print(" " , end ="")
    print("#")
    # Decreasing the user_input by 1
    # user_input -= 1

# Re-prompt the user for value b/w 1 and 8
def get_height():
    while True:
        user_input = int(input("Height: "))
        if 1 < user_input > 8:
            return user_input


main()






