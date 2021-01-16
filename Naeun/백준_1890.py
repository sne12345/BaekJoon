n = int(input())

mat = []
for i in range(n):
    mat.append(list(map(int, input().split())))



dp = [[0 for _ in range(n)] for _ in range(n)]
dp[0][0] = 1

for x in range(n):
    for y in range(n):
        if mat[x][y] == 0:
            break
        nx = x + mat[x][y]
        ny = y + mat[x][y]
        if 0 <= nx < n:
            dp[nx][y] += dp[x][y]
        if 0 <= ny < n:
            dp[x][ny] += dp[x][y]
        print(dp)

print(dp[n-1][n-1])



