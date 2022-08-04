#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <tuple>
#include <cstring>
using namespace std;

const int dy[4] = {1, 0, -1, 0};
const int dx[4] = {0, 1, 0, -1};
int R, C, swanX, swanY, visited[1501][1501], visitedSwan[1501][1501], cnt;
char _map[1501][1501];
bool isSwanMeet;
queue<pair<int, int> > waterQ, waterTmpQ, swanQ, swanTmpQ;

void Qclear(queue<pair<int, int> > &q)
{
    queue<pair<int, int> > empty; // queue 초기화 함수
    swap(q, empty);
}

void waterMelting() // 얼음에 대한 BFS
{
    while (waterQ.size()){
        int y = waterQ.front().first;
        int x = waterQ.front().second;
        waterQ.pop();
        for (int i = 0; i < 4; i++){
            int ny = y + dy[i];
            int nx = x + dx[i];
            if (ny < 0 || ny >= R || nx < 0 || nx >= C || visited[ny][nx])
                continue ;
            if (_map[ny][nx] == 'X'){
                visited[ny][nx] = 1; // 이동할 좌표가 얼음이라면 tmp에 저장후 .으로 바꿈
                waterTmpQ.push({ny, nx});
                _map[ny][nx] = '.';
            }
        }
    }
}

void moveSwan() // 백조에 대한 BFS
{
    while (swanQ.size()){
        int y = swanQ.front().first;
        int x = swanQ.front().second;
        swanQ.pop();
        for (int i = 0; i < 4; i++){
            int ny = y + dy[i];
            int nx = x + dx[i];
            if (ny < 0 || ny >= R || nx < 0 || nx >= C || visitedSwan[ny][nx])
                continue ;
            if (_map[ny][nx] == '.'){
                swanQ.push({ny, nx});
            }
            else if (_map[ny][nx] == 'X'){
                swanTmpQ.push({ny, nx}); // 이동할 죄표가 얼음이라면 tmp애 저장
            }
            else if (_map[ny][nx] == 'L'){
                isSwanMeet = true;
                return ;
            }
            visitedSwan[ny][nx] = 1;
        }
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    cin >> R >> C;
    for (int i = 0; i < R; i++){
        for (int j = 0; j < C; j++){
            cin >> _map[i][j];
            if (_map[i][j] == 'L'){
                swanY = i; swanX = j;
            }
            if (_map[i][j] == '.' || _map[i][j] == 'L'){
                visited[i][j] = 1, waterQ.push({i, j}); // 길이거나 백조위치라면 방문처리 후 waterQ에 push
            }
        }
    }
    swanQ.push({swanY, swanX}); // 백조의 위치에 대한 좌표 push후 방문처리
    visitedSwan[swanY][swanX] = 1;
    while (!isSwanMeet){
        moveSwan(); // 백조에 대한 BFS실행
        if (isSwanMeet){
            break ; // 백조를 만났다면 break
        }
        waterMelting(); // 얼음에 대한 BFS실행
        waterQ = waterTmpQ;
        swanQ = swanTmpQ;
        Qclear(waterTmpQ);
        Qclear(swanTmpQ);
        cnt++;
    }
    cout << cnt << '\n';
    return 0;
}