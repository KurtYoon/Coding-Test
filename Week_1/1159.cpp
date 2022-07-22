#include <iostream>
using namespace std;

int N, cnt[26];
string s, ret;

int main()
{
    cin >> N;
    for (int i = 0; i < N; i++)
    {
        cin >> s;
        cnt[s[0] - 'a']++;
    }
    for (int i = 0; i < 26; i++)
    {
        if (cnt[i] >= 5)
            ret += 'a' + i;
    }
    if (ret.size())
        cout << ret << '\n';
    else
        cout << "PREDAJA" << '\n';
    return 0;
}