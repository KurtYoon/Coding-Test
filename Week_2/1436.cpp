#include <iostream>
using namespace std;

int main(void)
{
    int start = 666, cnt = 0, tmp;
    int N;
    cin >> N;

    while (true)
    {
        tmp = start;

        while (tmp > 0)
        {
            if (tmp % 1000 == 666)
            {
                cnt++;
                break ;
            }
            tmp /= 10;
        }

        if (cnt == N)
        {
            cout << start << endl;
            break ;
        }
        start++;
    }
    return (0);
}