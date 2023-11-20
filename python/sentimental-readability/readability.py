from cs50 import get_string

# Might need try/except
text = get_string("Text: ")

# Count letters
letter_count = len(text)
print(letter_count)

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
    return (text.count(".") + text.count("!") + text.count("?"))

    # sentence_count = 0
    # for i in text:
    # if (text == "." or text == "!" or text == "?"):
    #     # Update count
    #     sentence_count += 1
    # return sentence_count




