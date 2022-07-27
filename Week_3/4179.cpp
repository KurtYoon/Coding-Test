#include <iostream>
#include <vector>
#include <algorithm>
#include <tuple>
#include <queue>
#include <cstring>
#define rep(i, x, n) for (int i = x; i < n; i++)
using namespace std;

const int INF = 987654321;
const int dy[4] = {0, -1, 0, 1};
const int dx[4] = {1, 0, -1, 0};
int R, C, fire[1004][1004], person[1004][1004], sy, sx, ret;
char a[1004][1004];
queue<pair<int, int> > q;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    fill(&fire[0][0], &fire[0][0] + 1004 * 1004, INF);
    cin >> R >> C;
    rep(i, 0, R){
        rep(j, 0, C){
            cin >> a[i][j];
            if (a[i][j] == 'F'){
                fire[i][j] = 1;
                q.push({i, j});
            }
            if (a[i][j] == 'J'){
                sy = i;
                sx = j;
            }
        }
    }
    while (q.size()){
        int y = q.front().first;
        int x = q.front().second;
        q.pop();
        rep(i, 0, 4){
            int ny = y + dy[i];
            int nx = x + dx[i];
            if (ny < 0 || nx < 0 || ny >= R || nx >= C)
                continue ;
            if (fire[ny][nx] != INF || a[ny][nx] == '#')
                continue ;
            fire[ny][nx] = fire[y][x] + 1;
            q.push({ny, nx});
        }
    }
    person[sy][sx] = 1;
    q.push({sy, sx});
    while (q.size()){
        int y = q.front().first;
        int x = q.front().second;
        q.pop();
        if (y == R || x == C || y == 1 || x == 1){
            ret = person[y][x];
            break ;
        }
        rep(i, 0, 4){
            int ny = y + dy[i];
            int nx = x + dx[i];
            if (ny < 0 || nx < 0 || ny >= R || nx >= C)
                continue ;
            if (person[ny][nx] == 1 || a[ny][nx] == '#')
                continue ;
            if (fire[ny][nx] <= person[ny][nx] + 1)
                continue ;
            person[ny][nx] = person[y][x] + 1;
            q.push({ny, nx});
        }
    }
    if (ret != 0){
        cout << ret << '\n';
    }
    else
        cout << "IMPOSSIBLE" << '\n';
    return 0;
}