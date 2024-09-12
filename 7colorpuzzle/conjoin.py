def p(num, n, m):
    out = []
    for i in range(n*m):
        if num&1: out.append(1)
        else: out.append(0)
        num>>=1
    for i in reversed(range(len(out))):
        print(out[i], end = '')
        if (i%n==0): print()

n, m = map(int, input().split())

gridRaw = []
for i in range(n):
    gridRaw.append(list(map(int, input().split())))
grid = [[] for i in range(m)]
mx = 3
for j in range(m):
    for i in range(n):
        grid[j].append(gridRaw[i][j])
        mx = max(mx, gridRaw[i][j])
print(grid)
gridbin = [0]*mx
for num in range(mx):
    for j in reversed(range(m)):
        for i in range(n):
            gridbin[num]<<=1
            if grid[j][i] >= num+1: gridbin[num]+=1


# p(gridbin[0], n, m)

l, w, h = map(int, input().split())

letters = []
for lett in range(l):
    key = input()
    num = 0
    lis = []
    for i in range(h):
        r = list(map(int, input().split()))
        lis.append(r)
    for j in reversed(range(w)):
        for i in range(h):
            num<<=1
            num+=lis[i][j]
    print(key)
    p(num, 3, 3)
    letters.append((key, num))



dp = dict()
# ans = []
def func(board):
    if board == (0, 0, 0):
        return ['']
    if dp.get(board, -1)==-1:
        works = []
        for letter in letters:
            if board[0]&letter[1]==letter[1]:
                currLetter = letter[1]
                layers = []
                for layer in reversed(board):
                    newLayer = layer^(layer&currLetter)
                    currLetter ^= (layer&currLetter)
                    layers.append(newLayer)
                layers.reverse()
                while layers[0]&7==0 and layers[0]!=0:
                    # print("shortened")
                    layers[0]>>=3
                    layers[1]>>=3
                    layers[2]>>=3
                newBoard = (layers[0], layers[1], layers[2])
                # print(f"trying {letter[0]}")
                # p(board[0], n, m)
                # print()
                # p(newBoard[0], n, m)
                ans = func(newBoard)
                if len(ans):
                    # print(f"{letter[0]} worked")
                    for suffix in ans: works.append(letter[0]+suffix)
                    # print(letter[0], end = '')
                # print(f"{letter[0]} didnt work")
        dp[board] = works
    return dp[board]

print(func((gridbin[0], gridbin[1], gridbin[2])))
# print(''.join(reversed(ans)))