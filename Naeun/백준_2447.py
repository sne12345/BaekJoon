

def stars(n):
    if n < 3:
        return

    a = (int)(n / 3)
    b = (int)(n / 3 * 2)

    for x in range(0,p,(int)(n)):
        for y in range(0,p,(int)(n)):
            for k in range(a, b):
                for l in range(a, b):
                    starli[x + k][y + l] = " "

    stars(n / 3)





p = (int)(input())

starli = [['*'] * p for i in range(p)]

stars(p)

for i in range(p):
    for j in range(p):
        if j == p-1:
            print(starli[i][j])
        else:
            print(starli[i][j], end="")

