from collections import deque
from copy import deepcopy as copy
import itertools
from pprint import pprint
import sys

# convert the input file into a 2d list of integers
RAW_STATEMENT = [
    list(map(int, line.split(" "))) for line in sys.stdin if not line.startswith("#")
]

implications = set(
    # a OR b <=> NOT a => b <=> NOT b => a
    # construct these implication pairs, and put them in a set to remove duplicates
    itertools.chain(*map(lambda x: ((-x[0], x[1]), (-x[1], x[0])), RAW_STATEMENT))
)

adjacency = {
    x[0]: set(clause[1] for clause in implications if clause[0] == x[0])
    for x in implications
}

# remove any cases of a => a, to simplify future assignments
for k in adjacency.keys():
    if k in adjacency[k]:
        adjacency[k].remove(k)

print("implication graph:")
pprint(adjacency)

# very inefficient :D
everything = set(
    itertools.chain(adjacency.keys(), *itertools.chain(adjacency.values()))
)

print(everything)
max_var = max(max(everything), abs(min(everything)))
min_var = -max_var
assignments = {var: None for var in range(min_var, max_var + 1)}

del assignments[0]

# setup work complete


def try_assignment(trial: type(assignments), var: int, val: bool) -> bool:
    if (trial[var] == (not val)) or (trial[-var] == val):
        return False
    trial[var] = val
    trial[-var] = not val
    return True


q = deque()
while None in assignments.values():
    # also insanely inefficient, sorry python gods
    var = list(assignments.keys())[list(assignments.values()).index(None)]

    false_mode = False

    trial = copy(assignments)
    if not try_assignment(trial, var, True):
        false_mode = True

    q.append(var)
    
    if not false_mode:
        print(q)
        while len(q)>0:
            n = q.popleft()
            # print(q)
            # q.extend(adjacency.get(n, set()))
            for adj in adjacency.get(n, set()):
                if trial[adj]: continue
                if not try_assignment(trial, adj, True):
                    false_mode = True
                    q.clear()
                    break
                q.append(adj)
            
            # print(adjacency.get(n, set()))

    if false_mode:
        # try assigning variable as false, and see what that implies

        print("false mode!")  # debug

        # throw away anything from "true mode"
        q.clear()
        trial = copy(assignments)

        var = -var
        if not try_assignment(trial, var, True):
            print("FALSE")
            exit(1)
        q.append(var)
        while len(q)>0:
            n = q.popleft()
            # print(q)
            
            for adj in adjacency.get(n, set()):
                if trial[adj]: continue
                if not try_assignment(trial, adj, True):
                    # throw away current trial, retry in false mode
                    print("FALSE")
                    exit(1)
                q.append(adj)
            
            # print(adjacency.get(n, set()))
    assignments = trial
print(assignments)