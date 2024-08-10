from cs50 import get_string

text = get_string("Text: ")

numlet = 0
for c in text:
    if c.isalpha():
        numlet += 1

numwor = 0
numsen = 0



    if (grade <= 1):
        print("Before Grade 1")
    elif (grade >= 16):
        print("Grade 16+")
    else:
        print(f"Grade {grade}")


def formula():
    global numlet, numwor, numsen
    L = (numlet * 100.0) / (numwor)
    S = (numsen * 100.0) / (numwor)
    index = round(0.0588 * L - 0.296 * S - 15.8)
    return index

main()
