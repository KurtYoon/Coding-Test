#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

const int dy[] = {-1, 0, 1, 0};
const int dx[] = {0, 1, 0, -1};
int M, N, K, y, x;
int a[101][101];
vector<int> ret;

int dfs(int y, int x)
{
    a[y][x] = 1;
    int _ret = 1;
    for (int i = 0; i < 4; i++)
    {
        int ny = y + dy[i];
        int nx = x + dx[i];
        if (ny < 0 || nx < 0 || ny >= M || nx >= N || a[ny][nx] == 1)
            continue ;
        _ret += dfs(ny, nx);
    }
    return _ret;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    cin >> M >> N >> K;
    while (K--)
    {
        int x1, y1, x2, y2;
        cin >> x1 >> y1 >> x2 >> y2;
        for (int i = y1; i < y2; i++)
            for (int j = x1; j < x2; j++)
                a[i][j] = 1;
    }
    for (int i = 0; i < M; i++)
    {
        for (int j = 0; j < N; j++)
        {
            if (a[i][j] != 1)
                ret.push_back(dfs(i, j));
        }
    }
    sort(ret.begin(), ret.end());
    cout << ret.size() << '\n';
    for (int i = 0; i < ret.size(); i++)
        cout << ret[i] << ' ';
    cout << '\n';
    return 0;
}