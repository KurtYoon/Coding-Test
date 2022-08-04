// 문자열 비교를 통해서 아스키코드값으로 최댓값 최솟값 정의
#include <iostream>
#include <cstring>
#include <algorithm>
#include <vector>
using namespace std;

int N, cnt[10];
char a[10];
vector<string> v;

bool _oper(char x, char y, char op)
{
    if (x < y && op == '<')
        return true;
    if (x > y && op == '>')
        return true;
    return false;
}

void Go(int idx, string num)
{
    if (idx == N + 1){
        v.push_back(num); // 기저사례
        return ;
    }
    for (int i = 0; i < 10; i++){
        if (cnt[i])
            continue ;
        if (idx == 0 || _oper(num[idx - 1], i + '0', a[idx - 1])){
            cnt[i] = 1;
            Go(idx + 1, num + to_string(i));
            cnt[i] = 0;
        }
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    cin >> N;
    for (int i = 0; i < N; i++){
        cin >> a[i];
    }
    Go(0, "");
    sort(v.begin(), v.end());
    cout << v[v.size() - 1] << '\n' << v[0] << '\n';
    return 0;
}