bestName = ""
bestRating = 0

def judge(month, day, year):
    if(int(year)<1928): return False
    elif(int(year)==1928):
        if(month in {"Jan", "Feb", "Mar", "Apr", "May", "Jun"}): return False
        elif(month == "Jul"):
            if(int(day[:-1])>7):
                return True
            return False
        else: return True
    else: 
        return True

for n in range(int(input())):
    name = input()
    date = input().split()
    rating = float(input())
    if(judge(date[0], date[1], date[2])):
        if(bestRating<rating):
            bestRating = rating
            bestName = name
print(bestName)