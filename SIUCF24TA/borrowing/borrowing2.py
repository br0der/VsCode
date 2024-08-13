import math

for _ in range(int(input())):
    num_friends, num_pens = [int(z) for z in input().strip().split(" ")]
    days = [int(z) for z in input().strip().split(" ")]
    # days.sort()
    pens_remaining = num_pens
    prev_day = 0
    friends_borrowing = 0
    for day in days:
        pens_borrowed = (day - prev_day) * friends_borrowing
        # print(day, pens_borrowed)
        if pens_borrowed > pens_remaining:
            print(prev_day + math.floor(pens_remaining/friends_borrowing))
            pens_remaining = 0
            break
        pens_remaining -= pens_borrowed
        prev_day = day
        friends_borrowing += 1
    if pens_remaining != 0:
        print(prev_day + math.floor(pens_remaining/friends_borrowing))