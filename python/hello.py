print("hello, world")

from cs50 import get_string

answer = get_string("What's your name? ")
print("hello, " + answer) # + Concatinating (joining) strings
print("hello,", answer) # Another way
print(f"hello, {answer}") # Best way. Format strings
