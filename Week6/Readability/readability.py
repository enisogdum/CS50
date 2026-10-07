
text = input("Text: ")

i = 0
numberLetter = 0
numberSentences = 0
numberWords = 1

for c in text:
    if c.isalpha():
        numberLetter += 1
    elif (c == '.') or (c == '!') or (c == '?') :
        numberSentences += 1
    elif c.isspace():
        numberWords += 1

index = (0.0588 * 100 * (numberLetter / numberWords)) - (0.296 * 100 * (numberSentences / numberWords)) - 15.8

if index < 1:
    print("Before Grade 1")
elif index < 16:
    print(f"Grade {round(index)}")
else:
    print("Grade 16+")


