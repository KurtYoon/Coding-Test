#include <iostream>
#include <vector>
using namespace std;

const int dy[4] = {0, 1, 0, -1};
const int dx[4] = {1, 0, -1, 0};

int R, C, K, visited[6][6], ans;
char a[6][6];

int dfs(int y, int x)
{
    int ret = 0;
    if (y == 0 && x == C - 1){
        if (K == visited[y][x]){
            return 1;
        }
        return 0;
    }
    for (int i = 0; i < 4; i++){
        int ny = y + dy[i];
        int nx = x + dx[i];
        if (ny < 0 || nx < 0 || ny >= R || nx >= C || visited[ny][nx] || a[ny][nx] == 'T')
            continue;
        visited[ny][nx] = visited[y][x] + 1;
        ret += dfs(ny, nx);
        visited[ny][nx] = 0;
    }
    return ret;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    cin >> R >> C >> K;

    for(int i = 0; i < R; i++){
        for (int j = 0; j < C; j++){
            cin >> a[i][j];
        }
    }
    visited[R - 1][0] = 1;
    dfs(R - 1, 0);
    cout << dfs(R - 1, 0) << '\n';
    return 0;
}