from sys import argv, exit
import csv

def max_repeat_count(string, substring):
    count = [0] * len(string)
    for i in range(len(string) - len(substring), -1, -1):
        if string[i: i + len(substring)] == substring:
            if i + len(substring) > len(string) - 1:
                count[i] = 1
            else:
                count[i] = 1 + count[i + len(substring)]

    return max(count)

def match(reader, original):
    for line in reader:
        name = line[0]
        values = [int(value) for value  in line[1:]]
        if values == original:
            print(name)
            return

    print("No Match.")

def main():

    if len(argv) != 3:
        print("Usage: python dna.py data.csv sequence.txt")
        exit(1)

    with open(argv[1]) as file:
        reader = csv.reader(file)

        all_sequences = next(reader)[1:] #array[1] to end.

        with open(argv[2]) as file1:
            string = file1.read()
                      #Below is List Comprehension method
            original = [max_repeat_count(string, seq) for seq in all_sequences]

        match(reader, original)



if __name__ == "__main__":
    main()