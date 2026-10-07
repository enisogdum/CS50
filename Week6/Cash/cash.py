try:
    money = float(input("Change: "))
except ValueError:
    money = float(input("Change: "))

while True:

    if money > 0:
        money = money * 100
        break
    else:
        money = float(input("Change: "))

if money == 0:
    print("0")
else:
    counter = 0
    moneyLeft = money

    while moneyLeft != 0:
        if moneyLeft >= 25:
            counter += int(moneyLeft / 25)
            moneyLeft = moneyLeft % 25

        elif moneyLeft >= 10:
            counter += int(moneyLeft / 10)
            moneyLeft = moneyLeft % 10

        elif moneyLeft >= 5:
            counter += int(moneyLeft / 5)
            moneyLeft = moneyLeft % 5

        else:
            counter += int(moneyLeft)
            moneyLeft = 0

print(counter)


