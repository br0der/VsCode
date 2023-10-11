for tc in range(int(input())):
    r, c = map(int, input().split())

    grid = []
    for _ in range(r):
        l = input()
        grid.append('')
        for i in range((len(l)//3)):
            grid[-1]+=l[i*3]
            grid[-1]+=l[i*3+1]
        grid[-1]+=l[-1]
    c = len(grid[0])
    start, end = (-1,-1), (-1,-1)
    for row in range(r):
        if grid[row][0] == '>':
            start = (row,0)
        if grid[row][0] == '<':
            end = (row,0)
        if grid[row][-1] == '<':
            start = (row, c-1)
        if grid[row][-1] == '>':
            end = (row, c-1)
    for col in range(c):
        if grid[0][col] == 'v':
            start = (0, col)
        if grid[0][col] == '^':
            end = (0,col)
        if grid[-1][col] == '^':
            start = (r-1, col)
        if grid[-1][col] == 'v':
            end = (r-1, col)

    q = [(start[0], start[1],0)]
    offs = [(0,1), (0,-1), (1,0), (-1,0)]
    visited = {start}
    o = -1
    # for i in grid:
    #     print(i)
    while len(q)>0:
        # print(q)
        row, col, d = q.pop(0)
        if (row, col) == end: 
            o = d
            break
        for rO, cO in offs:
            if (row+rO, col+cO) in visited: continue
            visited.add((row+rO, col+cO))
            if 0>row+rO or row+rO>=r or 0>col+cO or col+cO>=c: continue
            if grid[row+rO][col+cO] == '+' or grid[row+rO][col+cO] == '|' or grid[row+rO][col+cO] == '-': continue
            q.append((row+rO, col+cO, d+1))
    
    print(o//2)
