#include <iostream>
using namespace std;

long long A, B, C;

long long divide_and_conquer(long long a, long long b, long long c)
{
    if (b == 1)
        return a % c;
    long long ret = divide_and_conquer(a, b / 2, c);
    ret = (ret * ret) % c;
    if (b % 2)
        ret = (ret * a) % c;
    return ret;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    cin >> A >> B >> C;
    cout << divide_and_conquer(A, B, C) << '\n';
    return 0;
}

