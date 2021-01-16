from collections import deque
dx, dy = [0,0,1,-1], [1,-1,0,0]

n, m = map(int, input().split())
mat = []
for i in range(n):
    mat.append(list(map(int, input().split())))


ch = [[[0] * 4 for i in range(m)] for j in range(n)]
sx,sy,sz = map(int, input().split())
ex,ey,ez = map(int, input().split())

def bfs():
    queue = deque()
    queue.append((sx-1,sy-1,sz-1))
    while queue:
        x,y,z = queue.popleft()

        if x == ex - 1 and y == ey - 1 and z == ez - 1:
            print(ch[x][y][z])
            return

        for i in range(1,4):
            nx, ny = x + dx[z] * i, y + dy[z] * i

            if nx < 0 or nx >= n or ny < 0 or ny >= m:
                break
            if mat[nx][ny]:
                break
            if ch[nx][ny][z] == 0:
                queue.append((nx,ny,z))
                ch[nx][ny][z] = ch[x][y][z] + 1

        for i in range(4):
            if i == z:
                continue
            k = 2 if (i + z) % 4 == 1 else 1
            if ch[x][y][i] == 0:
                queue.append((x,y,i))
                ch[x][y][i] = ch[x][y][z] + k



bfs()