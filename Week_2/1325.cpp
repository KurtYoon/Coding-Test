#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring>

using namespace std;

int N, M, A, B, dp[10004], mx, visited[10004];
vector<int> v[10004];

int dfs(int here)
{
    visited[here] = 1;
    int ret = 1;
    for (int there : v[here]){
        if (visited[there])
            continue;
        ret += dfs(there);
    }
    return ret;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    cin >> N >> M;
    for (int i = 0; i < M; i++)
    {
        cin >> A >> B;
        v[B].push_back(A);
    }
    for (int i = 1; i <= N; i++)
    {
        memset(visited, 0, sizeof(visited));
        dp[i] = dfs(i);
        mx = max(dp[i], mx);
    }
    for (int i = 1; i <= N; i++){
        if (mx == dp[i]){
            cout << i << " ";
        }
    }
    return 0;
}