from cs50 import get_int

while True:
    card = get_int("Enter your Card Number: ")
    if card >= 0:
        break

def valid(card):
    sum = 0
    for i in range(len(str(card))):
        if i % 2 == 0:
            sum += card % 10
        else:
            digit = 2 * (card % 10)
            sum += digit // 10 + digit % 10

        card //= 10

    if sum % 10 == 0:
        return sum



def brand(card):
    num = int(str(card)[0:2])
    if (num == 34 or num == 37) and len(str(card)) == 15:
        print("AMEX")
    elif num > 50 and num < 56 and len(str(card)) == 16:
        print("MASTERCARD")
    elif num >= 40 and num < 50 and (len(str(card)) == 13 or len(str(card)) ==
                                     16):
        print("VISA")
    else:
        print("INVALID")

if valid(card):
    brand(card)
else:
    print("INVALID")