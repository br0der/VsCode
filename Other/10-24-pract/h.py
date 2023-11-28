def p(m,n,t):
    if t + n <= 1 or m < 0:
        return 0
    a = \
        n/(t+n) * (n-1)/(t+n-1) + \
        2*m/(t+n) * 1/(t+n-1) + \
        2*m/(t+n) * (2*m-2)/(t+n-1) * p(m-2,n,t-2) + \
        2*m/(t+n) * (t-2*m)/(t+n-1) * p(m-1,n,t-2) + \
        (2 * (t-2*m)/(t+n) * (t-2*m-1)/(t+n-1) * p(m,n,t-2) if t-2*m >= 1 else 0) + \
        2 * n/(t+n) * (t-2*m)/(t+n-1) * p(m,n-1,t-1) + \
        2 * n/(t+n) * 2*m/(t+n-1) * p(m-1,n-1,t-1)
    print(m, n, t, a)
    return a

print(1-p(500,200,1000))