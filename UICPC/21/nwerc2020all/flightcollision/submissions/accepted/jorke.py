#!/usr/bin/env python3

# Runs in O(nlog(n)), where n is the amount of cars
import heapq

class car:
    def __init__(self, i, x, v):
        self.i = i
        self.x = x
        self.v = v
        self.prv = None
        self.nxt = None

class crash:
    def __init__(self, car_left, car_right):
        self.left = car_left
        self.right = car_right
        self.dx = car_right.x - car_left.x
        self.dv = car_left.v - car_right.v

    def __lt__(self, other):
        if self.dv <= 0: # Crash never happens
            return False
        return self.dx * other.dv < self.dv * other.dx

# Read input
# O(n)
n = int(input())
cars = []
for i in range(n):
    x, v = [int(j) for j in input().split()]
    cars.append(car(i+1,x,v))

# Make linked list and set-up heap
# O(n) (+ O(nlog(n)) for the sort)
cars.sort(key = lambda c : c.x)
heap = []
for i in range(n-1):
    cars[i].nxt = cars[i+1]
    cars[i+1].prv = cars[i]
    heapq.heappush(heap, crash(cars[i], cars[i+1]))
first_car = cars[0]

# Main loop
# O(nlog(n)) since there are O(n) iterations
while len(heap) > 0 and heap[0].dv > 0:
    current = heapq.heappop(heap)

    # Check if both cars still exist
    if current.left.nxt != current.right or current.right.prv != current.left:
        continue

    # Update linked list
    prv = current.left.prv
    nxt = current.right.nxt
    if nxt != None: nxt.prv = prv
    if prv != None: prv.nxt = nxt
    else: first_car = nxt

    # Add new crash to heap
    if prv != None and nxt != None:
        heapq.heappush(heap, crash(prv, nxt))

# Print output
output = []
while first_car != None:
    output.append(first_car.i)
    first_car = first_car.nxt
print(len(output),end=' ')
print(*sorted(output))
