#!/usr/bin/python3
first = input()
second = input()
f = 0
s = 0
sticky = set()
while f < len(first):
    if first[f] != second[s]:
        sticky.add(second[s])
        s += 1
    f += 1
    s += 1
if s < len(second):
    sticky.add(second[s])
print(''.join(sticky))
