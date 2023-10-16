"""
Exercise 5: This program records the domain name (instead of the
address) where the message was sent from instead of who the mail came
from (i.e., the whole email address). At the end of the program, print
out the contents of your dictionary.
python schoolcount.py
Enter a file name: mbox-short.txt
{'media.berkeley.edu': 4, 'uct.ac.za': 6, 'umich.edu': 7,
'gmail.com': 1, 'caret.cam.ac.uk': 1, 'iupui.edu': 8}
"""

inp = input('Enter file name: ')
try:
    fhand = open(inp)
except:
    print("No such file")
    exit()

dictionary = dict()

for line in fhand:
    if line.startswith("From "):
        email = line.split()
        email = email[1]
        domain = email.split("@")
        try:
            domain = domain[1]
            if domain not in dictionary:
                dictionary[domain] = 1
            else:
                dictionary[domain] += 1                
        except:
            continue
            
print(dictionary)
