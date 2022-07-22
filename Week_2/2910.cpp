#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
#include <map>
using namespace std;
typedef pair<int, int> ii;

int N, C;
int a[1001];
map<int, int> m, mp;
vector<ii> v;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    cin >> N >> C;
    for (int i = 0; i < N; i++)
    {
        cin>>a[i];
        m[a[i]] += 1;
        if (mp[a[i]] == 0)
            mp[a[i]] = i + 1;
    }
    for (auto it : m)
    {
        v.push_back({it.second, it.first});
    }
    sort(v.begin(), v.end(), [](ii a, ii b)
    {
        if (a.first == b.first)
            return mp[a.second] < mp[b.second];
        return a.first > b.first;
    });
    for (auto c : v)
    {
        for (int i = 0; i < c.first; i++)
        {
            cout << c.second << ' ';
        }
    }
    return 0;
}