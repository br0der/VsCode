def wh(x):
    if x == 1:
        return("hour")
    else:
        return("hours")
def wm(x):
    if x == 0:
        return("")
    elif x == 1:
        return("minute")
    else:
        return("minutes")
for tc in range(int(input())):
    name = []
    curper = list(input())
    isit = True
    while isit == True:
        if curper[0] == ",":
            break
        name.append(curper[0])
        curper.pop(0)
    hours = 0
    minutes = 0
    for i in range(5):
        curper.pop(0)
        hours += int(curper[0]) * 10
        curper.pop(0)
        hours += int(curper[0])
        curper.pop(0)
        curper.pop(0)
        minutes += int(curper[0]) * 10
        curper.pop(0)
        minutes += int(curper[0])
        curper.pop(0)
    while minutes > 60:
        minutes -= 60
        hours += 1
    finalname = "".join(name)
    if minutes > 0:
        print(str(finalname) + "=" + str(hours) + " " + wh(hours) + " " + str(minutes) + " " + wm(minutes))
    else:
        print(str(finalname) + "=" + str(hours) + " " + wh(hours))