"""
Exercise 2: This program counts the distribution of the hour of the day
for each of the messages. You can pull the hour from the “From” line
by finding the time string and then splitting that string into parts using
the colon character. Once you have accumulated the counts for each
hour, print out the counts, one per line, sorted by hour as shown below.
python timeofday.py
Enter a file name: mbox-short.txt
04 3
06 1
07 1
09 2
10 3
11 6
14 1
15 2
16 4
17 2
18 1
19 1
"""

fhand = open("CH10/mbox-short.txt")
dictionary = dict()

for line in fhand:
    if line.startswith("From "):
        word = line.split()
        hour = word[5][:2]    
        if hour not in dictionary:
            dictionary[hour] = 1
        else:
            dictionary[hour] += 1
#print(dictionary)

lst = list()
for x, y in dictionary.items():
    lst.append((x, y))

lst.sort()
for x, y in lst:
    print(x, y)
