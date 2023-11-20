from cs50 import get_string

# Might need try/except
text = get_string("Text: ")

# Count letters
letter_count = len(text)

# Word count
def count_words(text):
    word_count = 1
    if text.isspace() in text:
        word_count += 1
    return word_count


