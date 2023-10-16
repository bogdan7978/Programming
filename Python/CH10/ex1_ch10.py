"""
Exercise 1: Revise a previous program as follows: Read and parse the
“From” lines and pull out the addresses from the line. Count the number of messages from each person using a dictionary.
After all the data has been read, print the person with the most commits
by creating a list of (count, email) tuples from the dictionary. Then
sort the list in reverse order and print out the person who has the most
commits.
Sample Line:
From stephen.marquard@uct.ac.za Sat Jan 5 09:14:16 2008
Enter a file name: mbox-short.txt
cwen@iupui.edu 5
Enter a file name: mbox.txt
zqian@umich.edu 195
"""
fhand = open("CH10/mbox-short.txt")
dictionary = dict()

for line in fhand:
    if line.startswith("From "):
        word = line.split()
        word = word[1]
        if word not in dictionary:
            dictionary[word] = 1
        else:
            dictionary[word] += 1
lst = list()
for email, count  in list(dictionary.items()):
    lst.append((count, email))

lst.sort(reverse=True)

for x, y in lst[0:1]:
    print(y, x)

