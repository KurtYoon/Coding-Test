#include <iostream>
#include <cstdio>
#include <queue>
#include <tuple>
using namespace std;

const int dy[] = {-1, 0, 1, 0};
const int dx[] = {0, 1, 0, -1};
int N, M, y, x;
int a[104][104], visited[104][104];

int main()
{
    scanf("%d %d", &N, &M);
    for (int i = 0; i < N; i++)
        for (int j = 0; j < M; j++)
            scanf("%1d", &a[i][j]);
    queue<pair<int, int> >q;
    visited[0][0] = 1;
    q.push(make_pair(0 ,0));
    while (q.size())
    {
        tie(y, x) = q.front();
        q.pop();
        for (int i = 0; i < 4; i++)
        {
            int ny = y + dy[i];
            int nx = x + dx[i];
            if (ny < 0 || ny >= N || nx < 0 || nx >= M || a[ny][nx] == 0)
                continue;
            if (visited[ny][nx])
                continue;
            visited[ny][nx] = visited[y][x] + 1;
            q.push(make_pair(ny, nx));
        }
    }
    printf("%d\n", visited[N - 1][M - 1]);
    return 0;
}
