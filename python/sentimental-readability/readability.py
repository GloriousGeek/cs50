from cs50 import get_string

# Might need try/except
text = get_string("Text: ")

# Count letters
letter_count = len(text)

# Word count
def count_words(text):
    # Initiating from 1 to include the last word
    word_count = 1
    for i in text:
        if i == " ":
            word_count += 1
    return word_count


def count_sentences(text):
    sentence_count = 1



