#!/usr/bin/python3

from random import randint

init = [x for x in range(100)]
boxes = []
while len(init) > 0:
    idx = randint(0, len(init) - 1)
    boxes.append( init[idx] )
    del init[idx]

worst = 0
for prisoner in range(100):
    check_idx = prisoner
    check_count = 0

    while (idx := boxes[check_idx]) != prisoner:
        check_idx = idx
        check_count += 1

    print(f"Prisoner {prisoner + 1} found their # in {check_count}")

    if worst < check_count:
        worst = check_count

print(f"Worst check was {worst}")
    