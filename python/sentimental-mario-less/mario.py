user_input = int(input("Height: "))
print(user_input)

# Re-prompt the user for value b/w 1 and 8
while True:
    user_input = int(input("Height: "))
    if 1 < user_input > 8:
        return user_input



for i in range(user_input):
    for j in range(user_input):
        print(" " , end ="")
    print("#")
    # Decreasing the user_input by 1
    # user_input -= 1



