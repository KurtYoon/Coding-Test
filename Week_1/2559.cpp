#include <iostream>
#include <algorithm>
using namespace std;

int N, K, r;
int cnt[100004];

int main()
{
    cin >> N >> K;
    for (int i = 1; i <= N; i++)
    {
        cin >> r;
        cnt[i] = cnt[i - 1] + r;
    }
    int ret = -10000004;
    for (int i = K; i <= N; i++)
    {
        ret = max(ret, cnt[i] - cnt[i - K]);
    }
    cout << ret << '\n';
    return 0;
}
