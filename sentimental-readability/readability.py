from cs50 import get_string

text = get_string("Text: ")

numlet = 0
for c in text:
    if c.isalpha():
        numlet += 1

numwor = len(text.split())

numsen = text.count(".") + text.count("!") + text.count("?")

L = (numlet * 100) / numwor

S = (numsen * 100) / numwor

grade = round(0.0588 * L - 0.296 * S - 15.8)

if (grade < 1):
    print("Before Grade 1")
elif (grade >= 16):
    print("Grade 16+")
else:
    print(f"Grade {grade}")
