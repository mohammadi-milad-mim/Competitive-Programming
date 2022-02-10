#!/usr/bin/python3
orig = input()
typoed = input()
for c in orig:
    typoed = typoed.replace(c, '', 1)
printed = []
out = ""
for c in typoed:
    if c not in printed:
        out += c
        printed += c
print(out)