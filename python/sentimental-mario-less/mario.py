user_input = int(input("Height: "))

# Re-prompt the user for value b/w 1 and 8
while (8 < user_input < 1):
    print(user_input)

for i in range(user_input, -1):
    print(" " * (user_input - 1), end ="")
    for j in range(user_input):
        print("#")

