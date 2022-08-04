// 동생의 위치와 수빈이의 위치를 체크
#include <iostream>
#include <algorithm>
#include <cstring>
#include <tuple>
#include <vector>
#include <queue>
using namespace std;

int N, K, max_n = 500000, visited[2][500001], flag, turn = 1; // K가 가지는 가속력 = 시간
pair<int, int> d[3] = {{1, 1}, {1, -1}, {2, 0}}; // 움직일 좌표

// 수빈이는 동생보다 먼저 도착해도 다시 방문할 수 있다 (+1 -1)
// 따라서 걸린 시간이 짝수일 때와 홀수일 때의 상태밖에 없기 때문에 visited[2][500001]로 선언함

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    cin >> N >> K;
    if (N == K){
        cout << 0 << '\n'; // N == K라면 시간 x
        return 0;
    }
    queue<int> q;
    visited[0][N] = 1;
    q.push(N);
    while (q.size()){
        K += turn; // 시간이 지날수록 K위치 변경
        if (K > max_n){ // 최댓값 이상 시 오류
            break ;
        }
        if (visited[turn % 2][K]){
            flag = 1; // 짝수일 때 동생의 위치라면 flag = 1후 break
            break ;
        }
        int qsize = q.size();
        for (int i = 0; i < qsize; i++){
            int x = q.front();
            q.pop();
            for (int j = 0; j < 3; j++){
                int nx = (x + d[j].second) * d[j].first;
                if (nx < 0 || nx > max_n || visited[turn % 2][nx])
                    continue ;
                visited[turn % 2][nx] = visited[(turn + 1) % 2][x] + 1; // 짝수가 아니었으므로 거리 추가
                if (nx == K){
                    flag = 1; // 새로운 좌표인 nx가 K에 도달했다면 flag = 1
                    break ;
                }
                q.push(nx); // queue에 새로운 좌표 추가
            }
        }
        if (flag){
            break ;
        }
        turn++; // 거리 1만큼 가속
    }
    if (flag){
        cout << turn << '\n'; // 가속 = 시간 출력
    }
    else{
        cout << -1 << '\n'; // -1 출력
    }
    return 0;
}