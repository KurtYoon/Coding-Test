#include <iostream>
#include <vector>
#include <algorithm>
#include <tuple>
#include <queue>
#include <cstring>
#define rep(i, x, n) for (int i = x; i <= n; i++) // for문 매크로
using namespace std;

const int INF = 987654321;
const int dy[4] = {0, -1, 0, 1};
const int dx[4] = {1, 0, -1, 0};
int R, C, fire[1004][1004], person[1004][1004], sy, sx, ret;
char a[1004][1004];

bool in(int a, int b){
    return 1 <= a && a <= R && 1 <= b && b <= C; // 유효값 이내에 존재하는지 확인
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    queue<pair<int, int> > q;
    fill(&fire[0][0], &fire[0][0] + 1004 * 1004, INF); // 먼저 fire INF로 초기화
    cin >> R >> C;
    rep(i, 1, R){
        rep(j, 1, C){
            cin >> a[i][j];
            if (a[i][j] == 'F'){ // F라면 fire에 1저장 후 queue에 push
                fire[i][j] = 1;
                q.push({i, j});
            }
            if (a[i][j] == 'J'){
                sy = i; // J라면 해당 좌표값 저장
                sx = j;
            }
        }
    }
    while (q.size()){
        int y = q.front().first; // queue에 저장되어 있는 좌표값 불러옴
        int x = q.front().second;
        q.pop();
        rep(i, 0, 3){
            int ny = y + dy[i];
            int nx = x + dx[i];
            if (!in(ny, nx)) // 유효한 값이 아니거나, fire이 방문했거나 벽이라면 continue
                continue ;
            if (fire[ny][nx] != INF || a[ny][nx] == '#')
                continue ;
            fire[ny][nx] = fire[y][x] + 1; //BFS알고리즘
            q.push({ny, nx}); // 새로운 좌표값 push
        }
    }
    person[sy][sx] = 1; // 지훈이의 좌표 방문 확인
    q.push({sy, sx}); // queue에 push
    while (q.size()){
        int y = q.front().first; // queue의 좌표 불러옴
        int x = q.front().second;
        q.pop();
        if (y == R || x == C || y == 1 || x == 1){ // 목표지점에 도달했다면 ret에 person에 저장되어 있는 값 저장
            ret = person[y][x];
            break ;
        }
        rep(i, 0, 3){
            int ny = y + dy[i];
            int nx = x + dx[i];
            if (!in(ny, nx)) // 유효값이 아니거나, 방문했거나 벽이라면 continue
                continue ;
            if (person[ny][nx] || a[ny][nx] == '#')
                continue ;
            if (fire[ny][nx] <= person[y][x] + 1) 
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