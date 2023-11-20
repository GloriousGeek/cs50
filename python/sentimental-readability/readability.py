from cs50 import get_string

# Might need try/except
text = get_string("Text: ")


# Count only letters (excluding spaces, numbers, and punctuation)
def count_letters(text):
    letter_count = 0
    for i in text:
        # Count only letters
        if i.isalpha():
            letter_count += 1
    return letter_count


print(count_letters(text))


# Word count
def count_words(text):
    # Initiating from 1 to include the last word
    word_count = 1
    for i in text:
        if i == " ":
            word_count += 1
    return word_count


def count_sentences(text):
    # The str.count() method returns the number of times a specified value appears in the string
    return text.count(".") + text.count("!") + text.count("?")


# Average # of letters per 100 words
L = (count_letters(text) / (count_words(text))) * 100
print(f"L {L}")

# Average sentences per 100 words
S = float((count_sentences(text) / (count_words(text)))) * 100
print(f"S {S}")

# Coleman-Liau index formula
index = round(0.0588 * L - 0.296 * S - 15.8)
print(f"Index {index}")

if index >= 16:
    print("Grade 16+")
elif index < 1:
    print("Before Grade 1")
else:
    print(f"Grade {index}")
