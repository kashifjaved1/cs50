height = input("Enter Height: ")
height = int(height)
spaces = height
for i in range(0, height):
    for spaces in range(1, spaces):
        print("", end=" ")
    --spaces
    for j in range(0, i+1):
        print("*", end="")

    print("",end="  ")

    for j in range(0, i+1):
        print("*", end="")
    print("\n")






