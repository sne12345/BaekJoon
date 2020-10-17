#include <iostream>
#include <string>
#include <algorithm>
#include <vector>

struct pos
{
    int x;
    int y;
};

char arr[11][11];
char visit[11][11];
int dy[8] = { -1, -1, 0, 1, 1,  1,  0, -1 };
int dx[8] = { 0,  1, 1, 1, 0, -1, -1, -1 };
bool isFilled = true;
std::vector<pos> tri;

bool cmp(const pos& first, const pos& second)
{
    if (first.y < second.y)
        return true;
    else if (first.y == second.y)
        return first.x < second.x;
    else
        return false;
}

void pp()
{
    std::cout << "-------------------\n";
    for (int y = 0; y <= 10; ++y)
    {
        for (int x = 0; x <= 10; ++x)
        {
            std::cout << visit[y][x];
        }
        std::cout << '\n';
    }

}

//정점을 찾아서 리턴함
pos FindVertex(int x, int y, int delta)
{
    while (true)
    {
        pos val = { x, y };
        visit[y][x] = '1';

        y += dy[delta];
        x += dx[delta];
        if (arr[y][x] == '0' || y < 1 || 10 < y || x < 1 || 10 < x)
        {
            return val;
        }
    }
}

void FindTri()
{
    for (int y = 1; y <= 10; ++y)
    {
        for (int x = 1; x <= 10; ++x)
        {
            if (arr[y][x] == '1')
            {
                tri.push_back({ x, y });
                //dy[8], dx[8]의 8방향 확인
                for (int i = 0; i < 8; ++i)
                {
                    //010
                    //111
                    //같은 상황에서 사용
                    if (arr[y + dy[3]][x + dx[3]] == '1' && arr[y + dy[4]][x + dx[4]] == '1' && arr[y + dy[5]][x + dx[5]] == '1' && i == 4) continue;
                    //111
                    //110
                    //100
                    //같은 상황에서 사용
                    if (arr[y + dy[2]][x + dx[2]] == '1' && arr[y + dy[3]][x + dx[3]] == '1' && arr[y + dy[4]][x + dx[4]] == '1' && i == 3) continue;
                    //아무것도 없는 경우
                    if (arr[y + dy[i]][x + dx[i]] == '0') continue;

                    pos tmp = FindVertex(x, y, i);
                    if (tmp.x != x || tmp.y != y)
                    {
                        //찾은 정점이 자기 자신이 아닌경우 정점을 벡터에 추가
                        tri.push_back(tmp);
                    }

                }

                return;
            }
        }
    }
}

//찾은 삼각형 말고 다른 삼각형이 있는지 확인함
bool FindOther()
{
    //    std::cout << '\n';
    for (int y = 1; y <= 10; ++y)
    {
        for (int x = 1; x <= 10; ++x)
        {
            //    std::cout << visit[y][x];
            if (visit[y][x] == '1')
            {
                continue;
            }

            if (arr[y][x] != '0')
            {
                return true;
            }
        }
        //    std::cout << '\n';
    }
    return false;
}

//찾은 삼각형의 내부가 1로 채워져 있는지 확인함, 플러드필처럼 동작함
void IsFilled(pos point)
{
    if (visit[point.y][point.x] == '0' && arr[point.y][point.x] == '1')
    {
        visit[point.y][point.x] = '1';
        for (int i = 0; i < 8; i += 2)
        {
            IsFilled({ point.x + dx[i], point.y + dy[i] });
        }
    }
    else if (visit[point.y][point.x] == '1' && arr[point.y][point.x] == '1')
    {
        return;
    }
    else if (visit[point.y][point.x] == '0' && arr[point.y][point.x] == '0')
    {
        isFilled = false;
    }
}

//맨 위 정점(a)에서 뻗어나온 두 정점(b, c)까지의 변 ab, ac와 별개로, 변 bc가 제대로 존재하는지 확인함
bool Fooooooo()
{
    //삼각형이 작아서 확인이 불가능한 경우
    //010 || 11 ||
    //111 || 10 || 등등
    //이러한 경우 참(변 bc가 제대로 존재한다)리턴함
    for (int i = 0; i < 8; ++i)
    {
        if (tri[1].x + dx[i] == tri[2].x && tri[1].y + dy[i] == tri[2].y)
        {
            return true;
        }
    }
    //맨 우측 하단 정점에서 좌측 하단 정점까지 값이 존재하는지 검사함
    pos drawline = { tri[1].x, tri[1].y };
    for (int i = 4; i < 8; ++i)
    {
        if (arr[drawline.y + dy[i]][drawline.x + dx[i]] == '1' && visit[drawline.y + dy[i]][drawline.x + dx[i]] == '0')
        {
            while (drawline.x != tri[2].x || drawline.y != tri[2].y)
            {
                drawline.x += dx[i];
                drawline.y += dy[i];
                //pp();

                if (arr[drawline.y][drawline.x] != '1')
                {
                    return false;
                }
                visit[drawline.y][drawline.x] = '1';
            }
            return true;
        }
    }
    return false;
}

//0001000000
//0011000000
//0111000000
//1111000000
//0000000000
//0000000000
//0000000000
//0000000000
//0000000000
//0000000000

//이등변 삼각형이 맞는지 확인하는 사실상의 메인 함수
bool IsRightTri()
{
    FindTri();

    //정점이 3개가 아닌경우 거짓
    if (tri.size() != 3)
    {
        return false;
    }

    //변 bc가 존재하지 않는경우 거짓
    if (Fooooooo() == false)
    {
        return false;
    }

    //이등변삼각형의 중심(삼각형의 중심 공식 사용)으로부터 삼각형의 내부가 다 채워져있는지 확인
    IsFilled({ (tri[0].x + tri[1].x + tri[2].x) / 3, (tri[0].y + tri[1].y + tri[2].y) / 3 });
    //귀찮아서 전역으로 뺌
    if (isFilled == false)
    {
        return false;
    }

    //삼각형 외부에 다른 값이 있는지 확인, 있으면 거짓
    if (FindOther())
    {
        return false;
    }

    //정점들의 y값부터 정렬
    std::sort(tri.begin(), tri.end(), cmp);
    //일단 급해서 마구잡이로 코드를 짬
    for (int i = 0; i < 2; ++i)
    {
        //하나의 변이 반드시 수직선과 수평선인 이등변삼각형의 경우 정점 3개의 y와 x값중 반드시 중복되는 값이 나타남.
        int vertexs[3];
        if (i == 0)
        {
            vertexs[0] = tri[0].y;
            vertexs[1] = tri[1].y;
            vertexs[2] = tri[2].y;
        }
        else
        {
            vertexs[0] = tri[0].x;
            vertexs[1] = tri[1].x;
            vertexs[2] = tri[2].x;
        }

        std::sort(vertexs, vertexs + 3);

        //그를 위해 각각의 값을 정렬, 중복값이 나온다면 이등변 삼각형
        if (vertexs[0] == vertexs[1] || vertexs[1] == vertexs[2])
        {
            return true;
        }
    }

    return false;
}
//1110000000
//1100000000
//1000000000
//0000000000
//0000000000
//0000000000
//0000000000
//0000000000
//0000000000
//0000000000
int main()
{
    //삼각형부터 제대로 찾아보자
    for (int y = 1; y <= 10; ++y)
    {
        std::string input;
        std::cin >> input;
        for (int x = 1; x <= 10; ++x)
        {
            arr[y][x] = input[x - 1];
            visit[y][x] = '0';
        }
    }

    if (IsRightTri() == false)
    {
        std::cout << 0;
        return 0;
    }
    else
    {
        for (int i = 0; i < 3; ++i)
            std::cout << tri[i].y << ' ' << tri[i].x << '\n';
        return 0;
    }
}
