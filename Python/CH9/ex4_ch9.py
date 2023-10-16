"""
Exercise 4: Add code to the above program to figure out who has the
most messages in the file. After all the data has been read and the dictionary has been created, look through the dictionary using a maximum
loop (see Chapter 5: Maximum and minimum loops) to find who has
the most messages and print how many messages the person has.
Enter a file name: mbox-short.txt
cwen@iupui.edu 5
Enter a file name: mbox.txt
zqian@umich.edu 195
"""

inp = input('Enter file name: ')
try:
    fhand = open(inp)
except:
    print("File not good")
    quit()

dictionary = dict()
largest= None
count = 0

for line in fhand:
    if line.startswith("From "):
        word = line.split()
        if word [1] not in dictionary:
            dictionary[word[1]] = 1
        else:
            dictionary[word[1]] = dictionary[word[1]] + 1



for numb, x in dictionary.items():
    if largest is None or x > largest:
        largest = x
        person = numb
    
print(person ,largest)
