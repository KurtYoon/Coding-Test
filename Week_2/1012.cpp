#include <iostream>
using namespace std;

const int dy[] = {-1, 0, 1, 0};
const int dx[] = {0, 1, 0, -1};
int T, M, N, K, X, Y;
int a[51][51], visited[51][51];

void dfs(int y, int x)
{
    visited[y][x] = 1;
    for (int i = 0; i < 4; i++)
    {
        int ny = y + dy[i];
        int nx = x + dx[i];
        if (ny < 0 || nx < 0 || ny >= N || nx >= M)
            continue;
        if (a[ny][nx] == 1 && !visited[ny][nx])
            dfs(ny, nx);
    }
    return ;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    cin >> T;
    while (T--)
    {
        cin >> M >> N >> K;
        fill(&a[0][0], &a[0][0]+51*51, 0);
        fill(&visited[0][0], &visited[0][0] + 51*51, 0);
        while (K--)
        {
            cin >> X >> Y;
            a[Y][X] = 1;
        }
        int ret = 0;
        for (int i = 0; i < N; i++)
        {
            for (int j = 0; j < M; j++)
            {
                if (a[i][j] == 1 && !visited[i][j])
                {
                    dfs(i, j);
                    ret++;
                }
            }
        }
        cout << ret << '\n';
    }
    return 0;
}