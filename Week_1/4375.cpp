#include <iostream>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    int N;
    while (cin >> N)
    {
        long long ret = 1;
        int cnt = 1;
        while (1)
        {
            if (ret == 0)
            {
                cout << cnt << '\n';
                break ;
            }
            else
            {
                ret = ret * 10 + 1;
                ret %= N;
                cnt++;
            }
        }
    }
    return 0;
}
