import random

# Generate a list of non-repeating integers
numbers = random.sample(range(1, 10001), 1000)

# Shuffle the list to put them in a random order
random.shuffle(numbers)

# Write the numbers to a text file
with open("1000_RNG.txt", "w") as file:
    for num in numbers:
        file.write(str(num) + "\n")

print("File generated successfully.")