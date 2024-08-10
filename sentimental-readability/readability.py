from cs50 import get_string

numlet = 0
numwor = 0
numsen = 0

def main():
    text = get_string("Text: ")

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

def formula()
