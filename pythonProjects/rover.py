for tc in range(int(input())):
    # try:
    d, rev, power, rpm, cap, v, dist = list(map(int, input().split()))
    if d == 0:
        print("Fail")
        continue
    if rpm == 0:
        print("Fail")
        continue
    if v == 0:
        v = 10000000000000
    circ = d * 3.14159265358979
    reqrev = (dist * 100 / circ) * rev
    time = reqrev / rpm
    reqpower = (reqrev * power / v) * (time / 60)
    if cap >= reqpower:
        print("Success " + f"{round(time, 4):0,.3f}")
    else:
        print("Fail")
    # except:
    #     print('Fail')