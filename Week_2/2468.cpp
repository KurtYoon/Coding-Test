#include <iostream>
using namespace std;

const int dy[] = {-1, 0, 1, 0};
const int dx[] = {0, 1, 0, -1};

int N;
int a[101][101], b[101][101], visited[101][101];

void dfs(int y, int x)
{
    visited[y][x] = 1;
    for (int i = 0; i < 4; i++)
    {
        int ny = y + dy[i];
        int nx = x + dx[i];
        if (ny < 0 || nx < 0 || ny >= N || nx >= N)
            continue;
        if (b[ny][nx] == 1 && !visited[ny][nx])
            dfs(ny, nx);
    }
    return ;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    int max = 1;
    int ret = 0;
    cin >> N;
    for (int i = 0; i < N; i++)
        for (int j = 0; j < N; j++)
            cin >> a[i][j];
    for (int d = 1; d < 101; d++)
    {
        ret = 0;
        fill(&b[0][0], &b[0][0]+101*101, 0);
        fill(&visited[0][0], &visited[0][0]+101*101, 0);
        for (int i = 0; i < N; i++)
        {
            for (int j = 0; j < N; j++)
            {
                if (a[i][j] > d)
                    b[i][j] = 1;
                else
                    b[i][j] = 0;
            }
        }
        for (int i = 0; i < N; i++)
        {
            for (int j = 0; j < N; j++)
            {
                if (b[i][j] == 1 && !visited[i][j])
                {
                    dfs(i, j);
                    ret++;
                }
            }
        }
        if (max < ret)
            max = ret;
    }
    
    cout << max << '\n';
    return 0;
}