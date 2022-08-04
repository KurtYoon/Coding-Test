#include <iostream>
#include <algorithm>
#include <cstring>
#include <queue>
#include <tuple>
#include <vector>
#define MAX 200000
using namespace std;

int N, K, ret;
int dist[MAX + 1], visited[MAX + 1];
pair<int, int> d[3] = {{1, 1}, {1, -1}, {2, 0}}; // 튜플 세팅
vector<int> v;
queue<int> q;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    cin >> N >> K;
    visited[N] = 1;
    q.push(N);
    while (q.size()){
        int here = q.front();
        q.pop();
        if (here == K){
            ret = visited[K]; // BFS 탈출조건
            break ;
        }
        for (int i = 0; i < 3; i++){
            int there = here * d[i].first + d[i].second; // 순간이동하는 경우의 수
            if (there >= MAX + 1 || there < 0 || visited[there]) // 유효값이 아니라면 continue
                continue ;
            visited[there] = visited[here] + 1;
            dist[there] = here; // 탐색 전의 좌표값을 저장함
            q.push(there);
        }
    }
    cout << ret - 1 << '\n';
    for (int i = K; i != N; i = dist[i]){
        v.push_back(i); // 마지막으로 순간이동한 지점부터 누적된 지점을 벡터에 저장
    }
    v.push_back(N);
    reverse(v.begin(), v.end()); 
    for (int i = 0; i < v.size(); i++){
        cout << v[i] << ' ';
    }
    return 0;
}