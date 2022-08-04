#include <iostream>
#include <cstring>
#include <algorithm>
#include <vector>
using namespace std;

const int dy[4] = {1, 0, -1, 0};
const int dx[4] = {0, 1, 0, -1};
int R, C, ret, visited[30];
char _map[21][21];

void Go(int y, int x, int cnt)
{
    ret = max(ret, cnt); // 최댓값 최신화
    for (int i = 0; i < 4; i++){
        int ny = y + dy[i];
        int nx = x + dx[i];
        if (ny < 0 || nx < 0 || ny >= R || nx >= C)
            continue ;
        int next = (int)(_map[ny][nx] - 'A'); // 다음 나아갈 알파벳 
        if (visited[next] == 0){
            visited[next] = 1;
            Go(ny, nx, cnt + 1);
            visited[next] = 0;
        }
    }
    return ;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    cin >> R >> C;
    for (int i = 0; i < R; i++){
        for (int j = 0; j < C; j++){
            cin >> _map[i][j];
        }
    }
    visited[(int)_map[0][0] - 'A'] = 1; // 좌측상단의 알파벳에 대한 방문처리
    Go(0, 0, 1);
    cout << ret << '\n';
    return 0;
}