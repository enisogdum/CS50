
number = str(input("Number: ",))
new_number = []

i = 0

while i < len(number):
    if number[i] != "-":
        new_number.append(number[i])

    i += 1

total = 0
digit_number = len(new_number)
while digit_number > 1:
    if 2 * int(new_number[digit_number - 2]) >= 10:
        total += (2 * int(new_number[digit_number - 2])) % 10 + 1
    else:
        total += 2 * int(new_number[digit_number - 2])
    digit_number -= 2

digit_number = len(new_number)

while digit_number > 0:
    total += int(new_number[digit_number - 1])
    digit_number -= 2

if total % 10 == 0:

    if int(new_number[0]) == 4 and (len(new_number) == 13 or len(new_number) == 16):
        print("VISA")
    else:
        num = int(new_number[0]) * 10 + int(new_number[1])
        if len(new_number) == 15 and (num == 34 or num == 37):
            print("AMEX")
        elif len(new_number) == 16 and (51 <= num <= 55):
            print("MASTERCARD")
        else:
            print("INVALID")

else:
    print("INVALID")

