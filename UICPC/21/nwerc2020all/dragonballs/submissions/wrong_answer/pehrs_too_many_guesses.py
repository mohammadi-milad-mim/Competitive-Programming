#!/usr/bin/env python3
import math
import random

LOW, HIGH = 0, 10 ** 6

def random_guess():
    x = random.randint(LOW, HIGH)
    y = random.randint(LOW, HIGH)
    print(x, y, flush=True)
    d = int(input())
    return (x, y, math.sqrt(d))

def guess_point(x, y):
    if x < LOW or x > HIGH or y < LOW or y > HIGH:
        return False
    print(x, y, flush=True)
    d = int(input())
    return d == 0

def find_intersection_points(a, b):
    (x0, y0, r0) = a
    (x1, y1, r1) = b
    d=math.sqrt((x1-x0)**2 + (y1-y0)**2)
    # non intersecting
    if d > r0 + r1 :
        return None
    # One circle within other
    if d < abs(r0-r1):
        return None
    # coincident circles
    if d == 0 and r0 == r1:
        return None
    else:
        a=(r0**2-r1**2+d**2)/(2*d)
        h=math.sqrt(r0**2-a**2)
        x2=x0+a*(x1-x0)/d
        y2=y0+a*(y1-y0)/d
        x3=x2+h*(y1-y0)/d
        y3=y2-h*(x1-x0)/d
        x4=x2-h*(y1-y0)/d
        y4=y2+h*(x1-x0)/d
        return map(round, (x3, y3, x4, y4))

n = int(input())
while n>0:
    points = []
    for i in range(0, 100):
        points.append(random_guess())
    intersections = [find_intersection_points(a, b) for a in points for b in points if a != b]
    for intersect in intersections:
        if intersect is not None:
            (x1, y1, x2, y2) = intersect
            if guess_point(x1, y1):
                n -= 1
                if n == 0:
                    break
            if guess_point(x2, y2):
                n -= 1
                if n == 0:
                    break