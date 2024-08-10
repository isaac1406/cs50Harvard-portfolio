from cs50 import get_string
# get text from input
text = get_string("Text: ")
# count number of letters in text
numlet = 0
for c in text:
    if c.isalpha():
        numlet += 1
# count number of words in text
numwor = len(text.split())
# count number of sentences in text
numsen = text.count(".") + text.count("!") + text.count("?")
# calculate average number of letters per 100 words
L = (numlet * 100) / numwor
# calculate average number of letters per 100 words
S = (numsen * 100) / numwor
# calculate grade level
grade = round(0.0588 * L - 0.296 * S - 15.8)
# print grade level
if (grade < 1):
    print("Before Grade 1")
elif (grade >= 16):
    print("Grade 16+")
else:
    print(f"Grade {grade}")
