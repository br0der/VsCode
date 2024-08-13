import random
cases = 25
case_input = []
maxX = 60
def pow2(x):
    assert(x>=0 and x<=maxX)
    pow2 = 1
    for i in range(x):
        pow2*=2
    return pow2

for i in range(0,14):
    case_input.append(pow2(i))

for i in range(1,10):
    case_input.append(pow2(random.randint(32,59)))

case_input.append(pow2(42))
case_input.append(pow2(60))
random.shuffle(case_input)

print(len(case_input))
assert(len(case_input) == cases)
for num in case_input:
    print(num)