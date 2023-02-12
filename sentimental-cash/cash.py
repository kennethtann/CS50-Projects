# TODO

from cs50 import get_float
import math

while True:
    cents = get_float("Change owed: ")
    if cents > 0:
            break

cents = cents * 100

quarters = math.floor(cents / 25)
remaining = cents - quarters * 25

dimes = math.floor(remaining / 10)
remaining = remaining - dimes * 10

nickels = math.floor(remaining / 5)
remaining = remaining - nickels * 5

pennies = math.floor(remaining / 1)

print(quarters + dimes + nickels + pennies)
