#include <iostream>
#include <algorithm>
#include <cstdlib>
#include <map>
using namespace std;
int N, M;
map<string, int> _map1;
map<int, string> _map2;
string s;
int main()
{
    ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
    cin >> N >> M;
    for (int i = 0; i < N; i++)
    {
        cin >> s;
        _map1[s] = i + 1;
        _map2[i + 1] = s;
    }
    for (int i = 0; i < M; i++)
    {
        cin >> s;
        if (atoi(s.c_str()) == 0)
            cout << _map1[s] << '\n';
        else
            cout << _map2[atoi(s.c_str())] << '\n';
    }
    return 0;
}
