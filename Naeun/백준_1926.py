
dx = [1,-1,0,0]
dy = [0,0,1,-1]

n, m = map(int, input().split())
check = [[0] * m for i in range(n)]

mat = []
for i in range(n):
    mat.append(list(map(int, input().split())))

def bfs(x,y):
    w = 1
    queue = [(x,y)]
    while queue:
        x, y = queue.pop()
        for i in range(4):
            nx, ny = x + dx[i], y + dy[i]
            if 0 <= nx < n and 0 <= ny < m :
                if mat[nx][ny] == 1 and not check[nx][ny]:
                    w += 1
                    check[nx][ny] = 1
                    queue.append((nx,ny))
    return w


cnt, wide = 0, 0
for i in range(n):
    for j in range(m):
        if mat[i][j] == 1 and not check[i][j]:
            cnt += 1
            check[i][j] = 1
            wide = max(wide, bfs(i,j))

print(cnt)
print(wide)




