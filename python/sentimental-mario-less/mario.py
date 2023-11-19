user_input = int(input("Height: "))
print(user_input)

# Re-prompt the user for value b/w 1 and 8
while (8 < user_input < 1):
    print(user_input)

for i in range(user_input):
    print(" " * (user_input - 1), end ="")
    for j in range(user_input):
        print("#")
    # Decreasing the user_input by 1
    # user_input -= 1



