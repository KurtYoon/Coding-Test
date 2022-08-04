// 지금까지 좌표에 대한 BFS를 수행했다면 뮤탈리스크는 3개의 좌표를 정점으로 가지는
// BFS를 수행하여아 한다.
#include <iostream>
#include <algorithm>
#include <vector>
#include <cstring>
#include <queue>
using namespace std;

int N, a[4], dp[64][64][64], visited[64][64][64];

struct A // tuple을 사용해도 되지만 귀찮음
{
    int a, b, c;
};

int _map[6][3] = {
    {9, 3, 1},
    {9, 1, 3},
    {3, 9, 1},
    {3, 1, 9},
    {1, 3, 9},
    {1, 9, 3}
};

queue<A> q;

int BFS(int a, int b, int c)
{
    visited[a][b][c] = 1;
    q.push({a, b, c});
    while (q.size())
    {
        int a = q.front().a;
        int b = q.front().b;
        int c = q.front().c;
        q.pop();
        if (visited[0][0][0])
            break ;
        for (int i = 0; i < 6; i++){
            int na = max(0, a - _map[i][0]);
            int nb = max(0, b - _map[i][1]);
            int nc = max(0, c - _map[i][2]); // 음수가 되는 것을 막아주는 코드
            if (visited[na][nb][nc])
                continue ;
            visited[na][nb][nc] = visited[a][b][c] + 1;
            q.push({na, nb, nc});
        }
    }
    return visited[0][0][0] - 1; // 정점
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    cin >> N;
    for (int i = 0; i < N; i++){
        cin >> a[i];
    }
    cout << BFS(a[0], a[1], a[2]) << '\n';
    return 0;
}