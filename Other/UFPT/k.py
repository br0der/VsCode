date = list(map(int, input().split()))
lis = [4,0,0,3,5,1,3,6,2,4,0,2]
days = ["Sunday", "Monday", "Tuesday", "Wednesday", "Thursday", "Friday", "Saturday"]
day = (date[0]+lis[date[1]-1]-1)%7
print(days[day])