print("hello, world")

import cs50

answer = get_string("What's your name?")
print("hello, " + answer) # + Concatinating (joining) strings
print("hello,", answer) # Another way
print(f"hello, {answer}") # Best way. Format strings
