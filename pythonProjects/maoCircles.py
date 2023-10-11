from math import sqrt
import copy
from functools import lru_cache
import random
# Function to find the circle on
# which the given three points lie
def define_circle(x1,y1,x2,y2,x3,y3):
    """
    Returns the center and radius of the circle passing the given 3 points.
    In case the 3 points form a line, returns (None, infinity).
    """
    temp = x2 * x2 + y2 * y2
    bc = (x1 * x1 + y1 * y1 - temp) / 2
    cd = (temp - x3 * x3 - y3 * y3) / 2
    det = (x1 - x2) * (y2 - y3) - (x2 - x3) * (y1 - y2)
    
    if abs(det) < 1.0e-6:
        return (None, float('inf'))
    
    # Center of circle
    cx = (bc*(y2 - y3) - cd*(y1 - y2)) / det
    cy = ((x1 - x2) * cd - (x2 - x3) * bc) / det
    
    radius = sqrt((cx - x1)**2 + (cy - y1)**2)
    return ((cx, cy), radius)

def dist(x1, y1, x2, y2):
    return sqrt((x2-x1)*(x2-x1) + (y2-y1)*(y2-y1))

inp = input().strip().split(',')
points = []
for i in range(0, len(inp), 2):
    points.append((float(inp[i][1:]), float(inp[i+1][:-1])))

setups = set()

for a in range(len(points)):
    x1, y1 = points[a]
    for b in range(a+1, len(points)):
        x2, y2 = points[b]
        for c in range(b+1, len(points)):
            x3, y3 = points[c]
            center, radius = define_circle(x1,y1,x2,y2,x3,y3)
            if center==None: continue
            points_in_circle = []
            for i, pt in enumerate(points):
                if abs(dist(pt[0], pt[1], center[0], center[1]) - radius) < 10e-5:
                    points_in_circle.append(i)
            setups.add(tuple(sorted(points_in_circle)))
            # print(numPointsAligned)
            # print(center, radius)
            # print(x1, y1, x2, y2, x3, y3)
# print(define_circle(0.0,0.0, 3.0,3.0, 2.0,2.0))
big_circles = [i for i in setups if len(i)>3]
big_circles.sort(key = lambda x: -len(x))
max_found = 0
# def dp(bit_map, nums_found):
#     global max_found
#     print(bin(bit_map)[2:])
#     if len(nums_found)==len(points): return bit_map
#     if saved[bit_map] != -1: return saved[bit_map]
#     max_found = max(max_found, len(nums_found))
#     for i in range(len(big_circles)):
#         if (1<<i) & bit_map: continue
#         temp_nums = copy.copy(nums_found)
#         for point in big_circles[i]:
#             temp_nums.add(point)
#         out = dp(bit_map^(1<<i), temp_nums)
#         saved[bit_map] = out
#         if out!=0:
#             return out
#     saved[bit_map] = 0
#     return 0
# @lru_cache
# def contains_all_points(used):
#     points_found = set()
#     for i in range(len(big_circles)):
#         if (1<<i) & used == 0: continue
#         for point in big_circles[i]:
#             points_found.add(point)
#     # print(points_found)
#     return len(points_found)>=len(points)

# m = float('inf')

# @lru_cache
# def findLeast(used):
#     global m
#     print(bin(used)[2:])
    
#     least = used.bit_count()
#     m = min(m, least)
#     print(m)
#     if m <= 7:
#         print(bin(used)[2:])
#         return least
#     # print('a')
#     for i in range(len(big_circles)):
        
#         if (1<<i) & used == 0: continue
        
#         if contains_all_points(used^(1<<i)):
#             # print('a')
#             out = findLeast(used^(1<<i))
#             # print(out)
#             least = min(least, out)
#             if out<=7: 
#                 return out
#     return least
max_found = 0
@lru_cache
def solve(found, used, first):
    global max_found
    
    if used.bit_count()>=7:
        # print('a')
        if found.bit_count()>max_found:
            
            max_found = found.bit_count()
            print(max_found)
        # max_found = max(max_found,found.bit_count())
        if max_found==len(points):
            print(bin(used)[2:])
            return True
        else:
            return False
    for i in range(len(big_circles)):
        if first:
            print(f'We are at index {i}')
        if ((1<<i) & used) > 0: continue
        # print(bin((1<<i))[2:], bin(used)[2:], (1<<i) & used)
        temp = found
        for point in big_circles[i]:
            temp|=(1<<point)
        if solve(temp, used^(1<<i), False):
            return True
    return False

# print(solve(0,0, True))

num = 9147945341419779
circles = []
for i in range(62):
    if num & (1<<i):
        # print(i)
        circles.append(big_circles[i])
eqs = []
circles.sort(key = lambda x: len(x))
for circle in circles:
    a, b, c = circle[0:3]
    a, b, c = points[a], points[b], points[c]
    eqs.append(define_circle(a[0],a[1],b[0],b[1],c[0],c[1]))
# eqs.sort(key = lambda x: x[0][0]-x[1])
def int_to_chr(i):
    return chr(round(i)+ord('a')-1)
# eqs.sort(key = lambda x: -x[1])
# order = [6,5,4,3,2,1,0]
for i in range(len(eqs)):
    a, b, c = eqs[i][0][0], eqs[i][0][1], eqs[i][1]
    print(int_to_chr(a), int_to_chr(b), int_to_chr(c), i, end = '\n')
# for i in range(len(points)):
#     print(f'({points[i][0]}, {points[i][1]})')
# print(points)