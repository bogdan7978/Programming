import re
inp = input("Enter a regular expression: ")
count = 0

fhand = open("CH11/mbox-short.txt")

for line in fhand:
    line = line.rstrip()
    fin = re.search(inp, line)
    if re.search(inp, line):
        count += 1

print(f"mbox-short.txt had {count} lines that matched {inp}")


    
