#include <iostream>
#include <algorithm>
#include <vector>
#include <cstring>
#include <cmath>
using namespace std;

int N, M, a[10][10], visited[10][10];
const int dy[] = {-1, 0, 1, 0};
const int dx[] = {0, 1, 0, -1};
vector<pair<int, int> > v;

void dfs(int y, int x)
{
    if (a[y][x] == 1 || visited[y][x])
        return;
    visited[y][x] = 1;
    for (int i = 0; i < 4; i++){
        int ny = y + dy[i];
        int nx = x + dx[i];
        if (ny < 0 || nx < 0 || ny >= N || nx >= M)
            continue;
        dfs(ny, nx);
    }
}

int solve()
{
    memset(visited, 0, sizeof(visited));
    for (int i = 0; i < N; i++){
        for (int j = 0; j < M; j++){
            if (a[i][j] == 2){
                dfs(i, j);
            }
        }
    }
    int ans = 0;
    for(int i = 0; i < N; i++){
        for (int j = 0; j < M; j++){
            if (!visited[i][j] && a[i][j] == 0){
                ans++;
            }
        }
    }
    return ans;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    cin >> N >> M;
    for (int i = 0; i < N; i++){
        for (int j = 0; j < M; j++){
            cin >> a[i][j];
            if (!a[i][j]){
                v.push_back(make_pair(i, j));
            }
        }
    }
    int ans = 0;
    for (int i = 0; i < v.size(); i++){
        for (int j = 0; j < i; j++){
            for (int k = 0; k < j; k++){
                a[v[i].first][v[i].second] = a[v[j].first][v[j].second] = a[v[k].first][v[k].second] = 1;
                ans = max(ans, solve());
                a[v[i].first][v[i].second] = a[v[j].first][v[j].second] = a[v[k].first][v[k].second] = 0;
            }
        }
    }
    cout << ans << '\n';
    return 0;
}