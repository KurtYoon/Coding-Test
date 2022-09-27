// 비활성 바이러스의 위치를 모두 저장해놓음
// 그 중에서 3개를 골라서 bfs를 돌림
// 3개를 뽑았을 때 visited의 값이 가장 적을 때가 최솟값

#include <iostream>
#include <algorithm>
#include <vector>
#include <string.h>
#include <queue>
#include <tuple>
#include <cstring>
using namespace std;

const int dy[] = {1, -1, 0, 0};
const int dx[] = {0, 0, 1, -1};
int N, M, a[54][54], visited[54][54], res = 987654321, x, y;
bool state[14];
vector<pair<int, int> > v;
queue<pair<int, int> > q;

void bfs()
{
    while (q.size()) {
        tie(y, x) = q.front();
        q.pop();
        for (int i = 0; i < 4; i++) {
            int ny = y + dy[i];
            int nx = x + dx[i];
            if (ny < 0 || nx < 0 || ny >= N || nx >= N)
                continue ;
            if (a[ny][nx] != 1 && visited[ny][nx] == -1) { // 벽이 아니고, 방문하지 않았을 경우
                visited[ny][nx] = visited[y][x] + 1;
                q.push(make_pair(ny, nx));
            }
        }
    }

    int time = 0;
    bool flag = true;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            if (a[i][j] == 0) {
                if (visited[i][j] == -1) { // 길인데 방문하지 않았다면 
                    flag = false;
                    break ;
                }
                else {
                    time = max(time, visited[i][j]); // 아니라면 방문배열의 최댓값
                }
            }
        }
    }
    if (flag)
        res = min(res, time);
}

void virus(int cnt, int idx) 
{
    if (cnt == M) {
        for (int i = 0; i < N; i++) {
            for (int j = 0; j < N; j++) {
                visited[i][j] = -1; // -1로 초기화
            }
        }
        for (int i = 0; i < v.size(); i++) {
        if (state[i] == true) {
            q.push(make_pair(v[i].first, v[i].second));
            visited[v[i].first][v[i].second] = 0; // 0으로 방문처리
            }
        }
        bfs();
        return ;
    }
    for (int i = idx; i < v.size(); i++) { // 재귀를 통해서 바이러스의 수만큼 찾음
        if (state[i] == true)
            continue ;
        state[i] = true;
        virus(++cnt, ++idx);
        state[i] = false;
        cnt--;
    }
    

}

void input()
{
    cin >> N >> M;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            cin >> a[i][j];
            if (a[i][j] == 2)
                v.push_back(make_pair(i, j));
        }
    }
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    input();
    virus(0, 0);
    
    if (res == 987654321)
        cout << -1;
    else
        cout << res;
    return 0;
}
