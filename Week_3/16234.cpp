#include <iostream>
#include <tuple>
#include <algorithm>
#include <cstring>
#include <vector>
using namespace std;

const int dy[4] = {0, -1, 0, 1};
const int dx[4] = {1, 0, -1, 0};
int N, L, R, a[54][54], visited[54][54], sum, cnt;
vector<pair<int, int> > v; // 탐색이 가능한 지점을 저장함 -> 평균값으로 수정하기 위해서

void dfs(int y, int x, vector<pair<int, int> > &v)
{
    for (int i = 0; i < 4; i++){
        int ny = y + dy[i];
        int nx = x + dx[i];
        if (nx < 0 || ny < 0 || nx >= N || ny >= N || visited[ny][nx]){
            continue ;
        }
        if (abs(a[ny][nx] - a[y][x]) >= L && abs(a[ny][nx] - a[y][x]) <= R){ // 나라의 인구차이가 조건내라면
            visited[ny][nx] = 1;
            v.push_back({ny, nx}); // 해당 좌표 저장
            sum += a[ny][nx]; // 인구수의 합 저장
            dfs(ny, nx, v); // 다시 dfs
        }
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    cin >> N >> L >> R;
    for (int i = 0; i < N; i++){
        for (int j = 0; j < N; j++){
            cin >> a[i][j];
        }
    }
    while (true)
    {
        bool flag = 0; // 인구이동의 유무를 확인하기 위해서
        memset(visited, 0, sizeof(visited)); // 반복해서 dfs 수행하므로 visited 초기화
        for(int i = 0; i < N; i++){
            for (int j = 0; j < N; j++){
                if (!visited[i][j]){ // 방문하지 않은곳이라면 벡터 초기화 후 현재 좌표 입력하고 dfs실행
                    v.clear();
                    visited[i][j] = 1;
                    v.push_back({i, j});
                    sum = a[i][j];
                    dfs(i, j, v);
                    if (v.size() == 1){
                        continue ;
                    }
                    for (pair<int, int> b : v){
                        a[b.first][b.second] = sum / v.size(); // 평균 인구수로 수정
                        flag = 1; // 인구 이동이 있었으므로 flag = 1
                    }
                }
            }
        }
        if (!flag) // 인구 이동이 없었다면 while 탈출
            break ;
        cnt++; // 인구 이동이 있었다면 ++
    }
    cout << cnt << '\n';
    return 0;
}