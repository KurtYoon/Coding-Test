#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring>
#include <queue>
#define MAX 100000
using namespace std;

int N, K;
int dist[MAX + 1]; // 최단거리가 담길 배열
long long cnt[MAX + 1]; // 최단거리의 경우의 수가 담길 배열

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    cin >> N >> K;
    if (N == K){
        puts("0"); puts("1");
        return 0;
    }
    dist[N] = 0;
    cnt[N] = 1;
    queue<int> q;
    q.push(N);
    while (q.size()){
        int here = q.front();
        q.pop();
        for (int there : {here-1, here+1, here*2}){ // 다음으로 향하는 경우의 수는 이 세가지 뿐
            if (0 <= there && there <= MAX){ // 다음 좌표가 유효값일때
                if (!dist[there]){ // 방문하지 않은 지점이라면
                    q.push(there);
                    dist[there] = dist[here] + 1; // 거리 추가
                    cnt[there] += cnt[here]; // 경우의수 + 1
                }
                else if (dist[there] == dist[here] + 1){ // 방문한 지점이라면
                    cnt[there] += cnt[here]; // 최단거리가 같은 지점이므로 경우의수 + 1
                }
            }
        }
    }
    cout << dist[K] << '\n';
    cout << cnt[K] << '\n';
    return 0;
}