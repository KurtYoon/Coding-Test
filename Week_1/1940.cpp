#include <iostream>
using namespace std;

int N, M;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    cin >> N >> M;
    int cnt[N];
    for (int i = 0; i < N; i++)
        cin >> cnt[i];
    int count = 0;
    if (M > 200000)
    {
        cout << 0 << '\n';
        return 0;
    }
    for (int i = 0; i < N; i++)
    {
        for (int j = i + 1; j < N; j++)
        {
            if (cnt[i] + cnt[j] == M)
                count++;
        }
    }
    cout << count << '\n';
    return 0;
}
