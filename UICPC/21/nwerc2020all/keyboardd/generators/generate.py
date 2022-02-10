#!/usr/bin/python3
import random
import string
import sys
import os

if len(sys.argv) != 3:
    print('Call with',sys.argv[0],"<filename> <seed>")
    print('e.g.',sys.argv[0],"data/secret/01-random.in 42")
    exit(1)

fn = sys.argv[1]
seed = sys.argv[2]

random.seed(seed)

letters = string.ascii_lowercase + ' '
with open(fn, 'w', newline='\n') as in_file:
    k = random.randint(1, len(letters))
    cs = random.sample(letters, k)
    text = random.choice(string.ascii_lowercase)+''.join(random.choices(letters, k=round(900 / (1 + k / len(letters)))))+random.choice(string.ascii_lowercase)
    text2 = text
    for c in cs:
        text2 = text2.replace(c, c+c)
    print(text, file=in_file)
    print(text2, file=in_file)
    with open(os.path.splitext(fn)[0] + '.ans', 'w', newline='\n') as ans_file:
        print(''.join(cs), file=ans_file)
