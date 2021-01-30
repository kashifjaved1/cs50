from cs50 import get_string

def count_letters(text):
    letters = 0
    for i in range(len(text)):
        if text[i].isalpha() and not(text[i].isspace()):
            letters += 1
    return letters

def count_words(text):
    words = 0
    for i in range(len(text)):
        if text[i].isspace():
            words += 1
    return words + 1

def count_sentences(text):
    sentences = 0
    for i in range(len(text)):
        if (text[i] == '.' or text[i] == '!' or text[i] == '?') :
            sentences += 1
    return sentences




text = get_string("Enter your Text: ")

total_letters = count_letters(text)
total_words = count_words(text)
total_sentences = count_sentences(text)

L = (total_letters / total_words * 100)
S = (total_sentences / total_words * 100)
index = round(0.0588 * L - 0.296 * S - 15.8)

if index < 1:
    print("Before Grade 1")
elif index >= 16:
    print("Grade 16+")
else:
    print("Grade " + str(index))


