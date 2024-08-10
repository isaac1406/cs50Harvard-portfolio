from cs50 import get_string

numlet = 0
global numwor
numsen = 0

def main():
    text = get_string("Text: ")

def counter(text):
    numlet = len(text)
    numwor = 0
    for i in range(len(text)):
        if text[i] = " ":
            numlet -= 1
        if text[i - 1] != ' ' & text[i] == ' ' & text[i + 1] != ' ':
            numwor += 1

