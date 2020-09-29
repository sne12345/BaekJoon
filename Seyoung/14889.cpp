#include <vector>
#include <algorithm>
#include <stdio.h>

const int INF = 987654321;

int N, result;
int team[21][21];

void DFS(string bit, int startTeam, int linkTeam)
{
        //N/2명씩 팀원을 가졌을 경우
        if (bit.size()==N)
        {
                 vector<int> start, link;
                 //팀원을 판별
                 for (int i = 0; i < bit.length(); i++)
                         if (bit[i] == '1')
                                 start.push_back(i);
                         else
                                 link.push_back(i);

                 //starTeam 점수 합산
                 int startTeamSum = 0;
                 for (int i = 0; i < start.size(); i++)
                         for (int j = i + 1; j < start.size(); j++)
                                 startTeamSum += (team[start[i]][start[j]] + team[start[j]][start[i]]);

                 //linkTeam 점수 합산
                 int linkTeamSum = 0;
                 for (int i = 0; i < link.size(); i++)
                         for (int j = i + 1; j < link.size(); j++)
                                 linkTeamSum += (team[link[i]][link[j]] + team[link[j]][link[i]]);
                 //result 업데이트
                 result = min(result, abs(startTeamSum - linkTeamSum));
                 return;
        }
        //한 팀당 N/2명
        if (startTeam < (N / 2))
                 DFS(bit + "1", startTeam + 1, linkTeam);
        if (linkTeam < (N / 2))
                 DFS(bit + "0", startTeam, linkTeam + 1);
}

int main(void)
{
        scanf("%d", &N);
        for (int i = 0; i < N; i++)
                 for (int j = 0; j < N; j++)
                         scanf("%d", &team[i][j]);
        result = INF;
        DFS("", 0, 0);
        printf("%d", result)
        return 0;
}
