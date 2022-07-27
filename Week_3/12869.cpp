#include <iostream>
#include <algorithm>
#include <vector>
#include <cstring>
using namespace std;

int N, a[4];
int sum, cnt;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    cin >> N;
    for (int i = 0; i < N; i++){
        cin >> a[i];
    }
    if (N == 1){
        sum = a[0];
        cnt += sum / 9;
        if (sum % 9)
            cnt += 1;
    }
    else if (N == 2){
        sum = a[0] + a[1];
        cnt += (sum) / 12;
        if (sum % 12)
            cnt += 1;
    }
    else if (N == 3){
        sum = a[0] + a[1] + a[2];
        cnt += (sum) / 13;
        if (sum % 13)
            cnt += 1;
    }
    cout << cnt << '\n';
    return 0;
}