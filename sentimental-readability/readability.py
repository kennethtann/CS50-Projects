# TODO

from cs50 import get_string


f = 0
g = 0
h = 0

text = get_string("Text: ")

letters = len(text)

#number of letters
for z in range(letters):
    if (text[z].isalpha()):
        f += 1

#number of words
for x in range(letters):
    if (text[x].isspace()):
        g += 1

#number of sentences
for y in range(letters):
    if (text[y] == '.' or text[y] == '?' or text[y] == '!'):
        h += 1

#CACULATION
coleman = (0.0588 * f / (g + 1) * 100) - (0.296 * h / (g + 1) * 100) - 15.8

index = round(coleman)

if index < 1:
    print("Before Grade 1")
elif index > 16:
    print("Grade 16+")
else:
    print(f"Grade {index}")