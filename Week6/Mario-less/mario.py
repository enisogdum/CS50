import cs50
try:
    height = int(input("Height: "))
except ValueError:
    height = int(input("Height: "))

while not 0 < height < 9:
    height = int(input("Height: "))

for i in range(height):
    for j in range(0, height - i - 1, 1):
        print(" ", end="")
    for j in range(0, i+1, 1):
        print("#", end="")
    print()
