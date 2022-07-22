#include <iostream>
#include <cstring>
#include <vector>
#include <algorithm>
using namespace std;

int cnt[26];
int vcnt, lcnt;
int flag;

bool is_alpha(char c)
{
    if (c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u')
        return true;
    return false;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    string s;
    while (cin >> s && s != "end")
    {    
        memset(cnt, 0, sizeof(cnt));
        flag = 0;
        lcnt = 0; vcnt = 0;
        for (int i = 0; i < s.length(); i++)
        {
            cnt[s[i] - 'a']++;
            if (is_alpha(s[i])){
                lcnt++; vcnt = 0;
            }
            else{
                vcnt++; lcnt = 0;
            }
            if (vcnt == 3 || lcnt == 3)
                flag = 1;
            if (i >= 1 && s[i] == s[i - 1] && (s[i] != 'e' && s[i] != 'o'))
                flag = 1;
        }
        if (!cnt['a' - 'a'] && !cnt['e' - 'a'] && !cnt['i' - 'a'] && !cnt['o' - 'a'] && !cnt['u' - 'a'])
            flag = 1;
        if (flag)
            cout << '<' << s << '>' << " is not acceptable.\n";
        else
            cout << '<' << s << '>' << " is acceptable.\n";
    }
    return 0;
}