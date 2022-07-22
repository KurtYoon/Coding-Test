#include <iostream>
#include <algorithm>
#include <cstring>
using namespace std;

int N, T;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    cin >> T;
    for (int i = 0; i < T; i++){
        cin >> N;
        int cnt = 0;
        for (int j = 5; j <= N; j *= 5)
            cnt += N / j;
        cout << cnt << '\n';
    }
    return 0;
}