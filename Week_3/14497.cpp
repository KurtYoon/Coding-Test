// 주난이가 0을 만나면 계속탐색, 1을 만나면 잠깐 멈춰서 cnt세기
#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring>
#include <tuple>
#include <queue>
using namespace std;

queue<pair<int, int> > q;
const int dy[4] = {0, -1, 0, 1};
const int dx[4] = {1, 0, -1, 0};
int N, M, x1, y1, x2, y2, cnt, visited[301][301];
char a[301][301];

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    cin >> N >> M;
    cin >> y1 >> x1 >> y2 >> x2;
    x1--, y1--, x2--, y2--; // 좌표값으로써 입력되기 때문에 --
    for (int i = 0; i < N; i++){
        for (int j = 0; j < M; j++){
            cin >> a[i][j];
        }
    }
    q.push({y1, x1});
    visited[y1][x1] = 1;
    while (a[y2][x2] != '0'){
        cnt++;
        queue<pair<int, int> > tmp;
        while (q.size()){
            int y = q.front().first;
            int x = q.front().second;
            q.pop();
            for (int i = 0; i < 4; i++){
                int ny = y + dy[i];
                int nx = x + dx[i];
                if (ny < 0 || nx < 0 || ny > N || nx > M || visited[ny][nx])
                     continue ;
                visited[ny][nx] = cnt; // 횟수에 기반한 BFS이므로 cnt를 사용
                if (a[ny][nx] != '0'){
                    a[ny][nx] = '0';
                    tmp.push({ny, nx}); // tmp는 nexp좌표들의 집합
                }
                else{
                    q.push({ny, nx});
                }
            }
        }
        q = tmp;
    }
    cout << visited[y2][x2] << '\n';
    return 0;
}