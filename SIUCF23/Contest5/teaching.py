for tc in range(int(input())):
    t, y = map(int,input().split())
    if t==1:
        print(0)
    else:
        # y = int(input())
        lo = 0
        hi = 10**9+1
        mid = -1
        while(lo<hi):
            mid = (lo+hi)//2
            # print(lo, hi, mid)
            sm = 1
            last = 1
            works = False
            for i in range(min(30, y, mid)):
                
                last*=mid-i
                sm+=last
                # print(last, sm, mid, '----')
                if(sm>=t or last>t):
                    works = True
                    break
            if not works:
                lo = mid+1
            else:
                hi = mid
        print(lo)