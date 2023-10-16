"""
Exercise 3: Write a program that reads a file and prints the letters
in decreasing order of frequency. Your program should convert all the
input to lower case and only count the letters a-z. Your program should
not count spaces, digits, punctuation, or anything other than the letters
a-z. Find text samples from several different languages and see how
letter frequency varies between languages. Compare your results with
the tables at https://wikipedia.org/wiki/Letter_frequencies.
"""
import string
#inp = input("enter file name: ")
fhand = open("CH10/mbox-short.txt")
dictionary = dict()

for line in fhand:
    line = line.rstrip("\n")
    line = line.lower()
    line = line.replace(" ", "")
    line = line.replace("-", "")
    line = line.translate(line.maketrans("", "", string.digits))
    line = line.translate(line.maketrans("", "", string.punctuation))
    for word in line:
        if word not in dictionary:
            dictionary[word] = 1
        else:
            dictionary[word] += 1
#print(dictionary)

lst = list()
for x, y in dictionary.items():
    lst.append((y, x))

lst.sort(reverse=True)

for x, y in lst:
    print(y, x)