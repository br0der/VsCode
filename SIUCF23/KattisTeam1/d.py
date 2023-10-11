from functools import lru_cache


num = int(input())

@lru_cache
def prm(num):
    total = 0
    i = 2
    while(i*i<=num):
        if((num%i)==0):
            total = prm(num//i)
            total+=i
            num = 1
            break
        i+=1
    if num!=1:
        total+=num
    return int(total)

while(num!=4):

    times = 0
    while(num!=4 and num!=1):
        # print(num)
        times+=1
        new = prm(num)
        if(new == num):
            break
        num = new
    print(f'{int(num)} {times}')
    num = int(input())

