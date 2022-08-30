// 2^40개의 경우의 수
// 행을 결정했다면 열의 최적의 수는 정해져 있음
#include <iostream>
#include <algorithm>
#include <cstring>
#include <tuple>
#include <vector>
using namespace std;

const int INF = 987654321;
int N, a[44], ret = INF;
string s;

void go(int here)
{
    // 열을 기반으로 행을 체크해야함
    if (here == N + 1){ // 만약 다 뒤집었다면 열에 대한 체크
        int sum = 0;
        for (int i = 1; i <= (1 << (N - 1)); i *= 2){ // 열에 대한 체크
            int cnt = 0;
            for (int j = 1; j <= N; j++){ // 행에 대한 체크
                if (a[j] & i){
                    cnt++;
                }
            }
            sum += min(cnt, N - cnt); // cnt : 열에 존재하는 T의 갯수
        }
        ret = min(ret, sum);
        return;
    }
    a[here] = ~a[here]; // 행에 대하여 뒤집기
    go(here + 1);
    a[here] = ~a[here]; // 행에 대하여 뒤집은 것을 다시 뒤집기 -> 원상태로
    go(here + 1);
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    cin >> N;
    for (int i = 1; i <= N; i++){
        cin >> s;
        int value = 1;
        for (int j = 0; j < s.size(); j++){
            if (s[j] == 'T'){
                a[i] |= value; // 어떠한 행에 대햐여 어떠한 값을 부여함 만약 THTHT라면 10101이라는 값을 부여함
            }
            value *= 2;
        }
    }
    go(1);
    cout << ret << '\n';
    return 0;
}
// 앞면 H 뒷면 T T를 최소로
// 몇번을 뒤집는 것은 상관없음. 그 때의 최솟값이 중요함