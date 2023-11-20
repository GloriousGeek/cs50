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
    # The str.count() method returns the number of times a specified value appears in the string
    return (text.count(".") + text.count("!") + text.count("?"))

    # sentence_count = 0
    # for i in text:
    # if (text == "." or text == "!" or text == "?"):
    #     # Update count
    #     sentence_count += 1
    # return sentence_count


# Average # of letters per 100 words
L = (letter_count/count_words()) * 100

# Average sentences per 100 words
S = (count_sentences()/count_words()) * 100

# Coleman-Liau index formula
index = round(0.0588 * L - 0.296 * S - 15.8)

if index >= 16:
    print("Grade 16+")
elif index < 1:
    print("Before Grade 1")
else:
    print(f"Grade {index}")


