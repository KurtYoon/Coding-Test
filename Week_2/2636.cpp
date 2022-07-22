#include <iostream>
#include <algorithm>
#include <cstring>
#include <vector>
using namespace std;

const int dy[] = {-1, 0, 1, 0};
const int dx[] = {0, 1, 0, -1};
int N, M, a[104][104], visited[104][104];
vector<pair<int ,int> > v;

void dfs(int y, int x)
{
    if (a[y][x] == 1){
        v.push_back(make_pair(y, x));
        return ;
    }
    for (int i = 0; i < 4; i++)
    {
        int ny = y + dy[i];
        int nx = x + dx[i];
        if (ny < 0 || nx < 0 || ny >= N || nx >= M || visited[ny][nx])
            continue ;
        visited[ny][nx] = 1;
        dfs(ny, nx);
    }
    return ;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    int T = 0, B;
    cin >> N >> M;
    for (int i = 0; i < N; i++){
        for (int j = 0; j < M; j++){
            cin >> a[i][j];
        }
    }
    while (true){
        B = 0;
        fill(&visited[0][0], &visited[0][0] + 104 * 104, 0);
        v.clear();
        dfs(0, 0);
        for (pair<int, int> b : v)
        {
            if (a[b.first][b.second] == 1){
                B++;
            }
        }
        for (pair<int, int> b : v)
            a[b.first][b.second] = 0;
        
        T++;
        bool flag = 0;
        for (int i = 0; i < N; i++){
            for (int j = 0; j < M; j++){
                if (a[i][j] != 0)
                    flag = 1;
            }
        }
        if (!flag)
            break;
    }
    cout << T << '\n' << B << '\n';
    return 0;
}