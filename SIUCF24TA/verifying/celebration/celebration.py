class node:
    def __init__(self, L, R):
        self.lo = L
        self.hi = R
        self.md = (L+R)//2
        self.sum = 0
        if self.lo == self.hi: return
        self.left = node(self.lo, self.md)
        self.right = node(self.md+1, self.hi)
    def update(self, idx, x):
        if self.lo == self.hi:
            self.sum += x
            return
        if idx <= self.md:
            self.left.update(idx, x)
        else:
            self.right.update(idx, x)
        self.sum = self.left.sum + self.right.sum
    def query(self, L, R):
        if R < self.lo or self.hi < L:
            return 0
        if L <= self.lo and self.hi <= R:
            return self.sum
        return self.left.query(L, R) + self.right.query(L, R)

def solve():
    n, m, q = map(int, input().split())
    seg_tree = node(0, m-1)
    arr = list(map(int, input().split()))
    for i in range(n):
        arr[i] -= 1
        seg_tree.update(arr[i], 1)
    
    shift = 0
    for _ in range(q):
        query = list(map(int, input().split()))
        if query[0] == 1:
            i = query[1]-1
            x = query[2]
            seg_tree.update(arr[i], -1)
            arr[i] = (arr[i] + x) % m
            seg_tree.update(arr[i], 1)
        if query[0] == 2:
            x = query[1]
            shift = (shift + x) % m
        if query[0] == 3:
            L = query[1] + m - shift - 1
            R = query[2] + m - shift - 1
            L %= m
            R %= m
            res = 0
            if L <= R:
                res = seg_tree.query(L, R)
            else:
                res = seg_tree.query(0, R) + seg_tree.query(L, m-1)
            print(res)

g = int(input())
for _ in range(g):
    solve()