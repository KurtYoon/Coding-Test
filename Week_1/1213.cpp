#include <iostream>
#include <algorithm>
using namespace std;

int cnt[26];

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    string s, t, h;
    int count = 0, pos = 0;
    cin >> s;
    for (int i = 0; i < s.length(); i++)
        cnt[s[i] - 'A']++;
    for (int i = 0; i < 26; i++)
    {
        if (cnt[i] & 1)
        {
            count++;
            pos = i;
            cnt[i]--;
        }
    }
    if (count > 1)
    {
        cout << "I'm Sorry Hansoo" << '\n';
        return 0;
    }
    for (int i = 0; i < 26; i++)
    {
        if (cnt[i] % 2 == 0 && cnt[i])
        {
            while (cnt[i])
            {    
                t += 'A' + i;
                cnt[i] -= 2;
            }
        }
    }
    h = t;
    reverse(h.begin(), h.end());
    if (count == 1)
        t += 'A' + pos;
    t += h;
    cout << t << '\n';
    return 0;
}