#include <iostream>
#include <cstring>
#include <cstdlib>
#include <algorithm>
#include <vector>
using namespace std;

int N;
string s, a;
vector<string> v;

void go()
{
    if(a.size())
    {
        while (1)
        {
            if (a.size() && a.front() == '0')
                a.erase(a.begin());
            else
                break ;
        }
        if (a.size() == 0)
            a = "0";
        v.push_back(a);
        a = "";
    }
}

bool cmp(string a, string b)
{
    if (a.size() == b.size())
        return a < b;
    return a.size() < b.size();
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    cin >> N;
    for (int i = 0; i < N; i++){
        cin >> s;
        a = "";
        for (int j = 0; j < s.size(); j++)
        {
            if (s[j] >= '0' && s[j] <= '9')
                a += s[j];
            else
                go();
        }
        go();
    }
    sort(v.begin(), v.end(), cmp);
    for (string c : v)
        cout << c << '\n';
    return 0;
}