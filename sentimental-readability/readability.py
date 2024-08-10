from cs50 import get_string

numlet = 0
numwor = 0
numsen = 0

def main():
    text = get_string("Text: ")
    counter(text)
    grade = formula()

    if (grade <= 1):
        print("Before Grade 1")
    elif (grade >= 16):
        print("Grade 16+")
    else:
        print(f"Grade {grade}")

def counter(text):
    global numlet, numwor, numsen
    numlet = len(text)

    for i in range(len(text)):
        if text[i] == " " | text[i] == ",":
            numlet -= 1
        if text[i - 1] != ' ' & text[i] == ' ' & text[i + 1] != ' ':
            numwor += 1
        if text[i] == '!' | text[i] == '?' | text[i] == '.':
            numsen += 1

def formula():
    global numlet, numwor, numsen
    L = (numlet * 100.0) / (numwor)
    S = (numsen * 100.0) / (numwor)
    index = round(0.0588 * L - 0.296 * S - 15.8)
    return index

main()
