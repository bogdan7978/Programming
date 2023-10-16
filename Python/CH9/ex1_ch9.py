"""
Exercise 1: Download a copy of the file www.py4e.com/code3/words.txt
Write a program that reads the words in words.txt and stores them as
keys in a dictionary. It doesn’t matter what the values are. Then you
can use the in operator as a fast way to check whether a string is in the
dictionary.
"""

fhand = open("words.txt")
dictionary = dict()
count = 0 
for line in fhand:
    words = line.split()
    for word in words:
        words = line.split()
        dictionary[word] = [count]
        count += 1

print(dictionary)
print("moon" in dictionary)
print("Writing" in dictionary)