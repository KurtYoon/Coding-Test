#include <iostream>
#include <map>
using namespace std;
int N, M;
string a, b;

int main()
{
    ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
    cin >> N;
    while (N--)
    {
        map<string, int> _map;
        cin >> M;
        for (int i = 0; i < M; i++)
        {
            cin >> a >> b;
            _map[b]++;
        }
        long long ret = 1;
        for (auto c : _map)
            ret *= ((long long)c.second + 1);
        ret -= 1;
        cout << ret << '\n';
    }
    return 0;
}
