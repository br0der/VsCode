import random
import sys 
sys.set_int_max_str_digits(400000)
cases = 50
case_input = []
maxX = 100*100*100
def pow2(x):
    assert(x>=0 and x<=maxX)
    pow2 = 1
    for i in range(x):
        pow2*=2
    return pow2

def fastPow(ex):
    assert(ex>=0 and ex<=maxX)
    if(ex==0): return 1
    sqt = fastPow(ex//2)
    ans =  sqt * sqt
    if(ex%2 == 1): ans*=2
    return ans

for i in range(1,15):
    case_input.append(pow2(i))

for i in range(1,9):
    case_input.append(pow2(random.randint(32,59)))

case_input.append(pow2(60))
case_input.append(pow2(42))
case_input.append(pow2(100))

#large data 
for i in range(1,100):
    assert(fastPow(i) == pow2(i))

case_input.append(fastPow(61))
case_input.append(fastPow(62516))
case_input.append(fastPow(62507))
case_input.append(fastPow(12506))
case_input.append(fastPow(2505))
for i in range(maxX,maxX-10,-1):
    case_input.append(fastPow(i))

for i in range(5):
    case_input.append(fastPow(random.randint(20000,100000)))

while(len(case_input) < cases):
    case_input.append(fastPow(random.randint(500000,900000)))


random.shuffle(case_input)

print(len(case_input))
assert(len(case_input) == cases)
for num in case_input:
    print(num)